#include <type_traits>
#include <new>
#include <iostream>

#include "lambdapure/Dialect.h"
#include "lambdapure/MLIRGen.h";
#include "lambdapure/Parser.h"
#include "lambdapure/lexer.h"
#include "lambdapure/Passes.h"
#include "lambdapure/TranslateToCpp.h"

#include "mlir/ExecutionEngine/ExecutionEngine.h"
#include "mlir/ExecutionEngine/OptUtils.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/Module.h"
#include "mlir/IR/Verifier.h"
#include "mlir/InitAllDialects.h"
#include "mlir/Parser.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Pass/PassManager.h"
#include "mlir/Target/LLVMIR.h"
#include "mlir/Transforms/Passes.h"


#include "llvm/ADT/StringRef.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/ErrorOr.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"



using namespace lambdapure;
namespace cl = llvm::cl;

//Parse Commandline
//----------------------------------------------------------------------------
static cl::opt<std::string> inputFilename(
                                     cl::Positional,
                                     cl::desc("<input lambdapure file>"),
                                     cl::Required,
                                     cl::value_desc("filename")
);

static cl::opt<std::string> outputFilename (
                                  "o",
                                  cl::init("a"),
                                  cl::desc("Specify output filename"),
                                  cl::value_desc("filename")
);

static cl::opt<bool> dumpAST("ast", cl::desc("AST dump"),cl::init(false));


static cl::opt<bool> dumpMLIR("mlir",cl::desc("MLIR dump"),cl::init(false));

static cl::opt<bool> runtimeLowering("runtime",cl::desc("Runtime dump"),cl::init(false));

static cl::opt<bool> refCount("ref",cl::desc("Ref Count"),cl::init(false));

static cl::opt<bool> desUpdates("des",cl::desc("DestructiveUpdates"),cl::init(false));


//----------------------------------------------------------------------------

std::unique_ptr<ModuleAST> parseInputFile(llvm::StringRef inputFilename){
  llvm::ErrorOr<std::unique_ptr<llvm::MemoryBuffer>> fileOrErr = llvm::MemoryBuffer::getFileOrSTDIN(inputFilename);
  if (std::error_code EC = fileOrErr.getError()) {
    llvm::errs() << "Could not open input file: " << EC.message() << "\n";
    return nullptr;
  }
  if(!llvm::StringRef(inputFilename).endswith(".lambdapure")){
    llvm::errs() << "Input filetype does not end with lambdapure" << "\n";
    return nullptr;
  }
  llvm::StringRef buffer = fileOrErr.get()->getBuffer();
  std::string filename = inputFilename.str();
  Lexer lexer = Lexer(filename, buffer);
  Parser parser = Parser(lexer);
  return parser.parse();
}





int main(int argc, char **argv){
  cl::ParseCommandLineOptions(argc, argv);
  mlir::OwningModuleRef module;



  auto ast =  parseInputFile(inputFilename);
  if(!ast){
    return -1;
  }
  if(dumpAST){
    ast -> print();
  }
  mlir::registerAllDialects();
  mlir::registerDialect<mlir::lambdapure::LambdapureDialect>();
  mlir::MLIRContext context;

  module = mlirGen(context, *ast);
  mlir::PassManager pm(&context);
  if(dumpMLIR)
    module -> dump();

  if(desUpdates){
    pm.addPass(mlir::lambdapure::createDestructiveUpdatePattern());
  }




  if(runtimeLowering || refCount ){
    pm.addPass(mlir::lambdapure::createLambdapureToLeanLowering());
  }

  if(refCount ){
    pm.addPass(mlir::lambdapure::createReferenceRewriterPattern());
  }



  pm.run(*module);
  if(runtimeLowering){
    auto m = *module;
    lambdapure::translate(m);
  }
  if(dumpMLIR)
    module -> dump();

  return 0;
}
