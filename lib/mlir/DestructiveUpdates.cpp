#include "lambdapure/Dialect.h"
#include "lambdapure/Passes.h"
#include <iostream>
#include "mlir/IR/Matchers.h"
#include "mlir/IR/PatternMatch.h"


#include "mlir/Support/LLVM.h"
#include "mlir/Support/LogicalResult.h"

#include "mlir/Pass/Pass.h"
#include "mlir/Transforms/DialectConversion.h"

using namespace mlir;

namespace{
  struct ConstructorOpLowering : public OpRewritePattern<lambdapure::ConstructorOp> {
  using OpRewritePattern<lambdapure::ConstructorOp>::OpRewritePattern;

  LogicalResult matchAndRewrite(lambdapure::ConstructorOp op,
                                PatternRewriter &rewriter) const final {
    return success();
  }
};
}


namespace{
class DestructiveUpdatePattern
    : public mlir::PassWrapper<DestructiveUpdatePattern, FunctionPass> {
public:
  void runOnFunction() override {
    auto f = getFunction();
    std::vector<mlir::Value> args;
    for(int i = 0; i <f.getNumArguments();++i ){
      auto val = f.getArgument(i);
      auto type = val.getType();
      if(mlir::lambdapure::ObjectType::classof(type)){
          args.push_back(val);
      }
    }
    runOnRegion(args,f.getBody());
  }
  void runOnRegion(std::vector<mlir::Value> args,mlir::Region &region){
    for(auto it = region.op_begin(); it != region.op_end();++it ){
      auto context = it -> getContext();
      auto builder = mlir::OpBuilder(context);
      auto name = it -> getName().getStringRef().str();
      if(name == "lambdapure.ConstructorOp"){
        Operation *op = &*it;
        std::vector<mlir::Value> resets = checkControlPath(args,op);
        if(!resets.empty()){

          mlir::Value reuseObject = resets[0];


          int tag = op -> getAttrOfType<IntegerAttr>("tag").getInt();
          std::vector<mlir::Value> operands = std::vector<mlir::Value>();
          operands.push_back(reuseObject);
          for(auto operand = op -> operand_begin(); operand != op -> operand_end();++operand){
            operands.push_back(*operand);
          }
          auto original_block = &*region.begin();
          // auto firstOp = original_block -> begin();
          // auto sBlock = original_block -> splitBlock(firstOp);


          // builder.setInsertionPointToStart(original_block);
          //
          // auto resetOp = builder.create<lambdapure::ResetOp>(builder.getUnknownLoc(),reuseObject,2);
          //
          // auto &new_region_1 = resetOp.getRegion(0);
          // auto new_block_1 = builder.createBlock(&new_region_1);
          // auto &new_region_2 = resetOp.getRegion(1);
          // auto new_block_2 = builder.createBlock(&new_region_2);



          //
          // for(auto op = --(original_block -> end()); op != original_block -> begin();--op){
          //
          //   builder.setInsertionPointToStart(new_block_1);
          //   auto new_op_1 = op -> clone();
          //   builder.insert(new_op_1);
          //   builder.setInsertionPointToStart(new_block_2);
          //   auto new_op_2 = op -> clone();
          //   builder.insert(new_op_2);
          // }




          // builder.setInsertionPoint(op);
          // auto new_result = builder.create<lambdapure::ReuseConstructorOp>(op -> getLoc(),tag,operands);
          // op -> replaceAllUsesWith(new_result);
          // op -> erase();

        }
      }
      if(name == "lambdapure.CaseOp"){
        //call recursively the next region with copied arg vector
        std::vector<mlir::Value> new_args(args);
        for(int i = 0 ; i < it ->getNumRegions();++i){
          auto &region = it -> getRegion(i);
          runOnRegion(new_args,region);
        }
      }
    }
  }

  std::vector<mlir::Value> checkControlPath(std::vector<mlir::Value> &args,Operation *op){
    //here we check if any potential reuse objects in args has an operation which uses the reuseObject
    //And is an ancestor, then we return a vector off all potential reuseObject
    std::vector<mlir::Value> res_args(args);
    for(int i = 0;i < res_args.size() ;++i){
      // if(res_args[i])
      for(auto user_it = res_args[i].user_begin() ; user_it != res_args[i].user_end(); ++user_it){
        if(!(user_it -> isProperAncestor(op))){
          //remove potential reuse if the value is used by ancestor of constructor
          res_args.erase(res_args.begin() + i);
        }
      }
    }

    return res_args;
  }
};


}//end anonymous namespace

std::unique_ptr<Pass> mlir::lambdapure::createDestructiveUpdatePattern(){
  return std::make_unique<DestructiveUpdatePattern>();
}
