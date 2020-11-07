



// #include "llvm/ADT/Optional.h"
// #include "llvm/ADT/STLExtras.h"
// #include "llvm/ADT/StringExtras.h"
// #include "llvm/Support/raw_ostream.h"

#include <map>
#include <utility>
#include <vector>
#include <memory>
#include <iostream>

#include "Ast.h"
#include "Lexer.h"

namespace lambdapure{

class Parser{

private:
  Lexer &lexer;

// we can ignore binop precedence as there are none builtin

VarType ParseType(){
  VarType result;
  if(lexer.getId() == "obj"){
    result = object;
  }
  else if(lexer.getId() == "u8") {
    result = u8;
  }
  else if(lexer.getId() == "u16"){
    result = u16;
  }
  else if(lexer.getId() == "u32"){
    result = u32;
  }
  else if(lexer.getId() == "u64"){
    result = u64;
  }

  lexer.getNextToken();// consume type
  return result;
}

std::unique_ptr<NumberExprAST> ParseNumberExpr(){
  auto res = std::make_unique<NumberExprAST>(lexer.getValue());
  lexer.getNextToken();//consume number
  return std::move(res);
}
std::unique_ptr<VariableExprAST> ParseVarExpr(){
  auto res = std::make_unique<VariableExprAST>(lexer.getId());
  lexer.getNextToken();//consume var
  return std::move(res);
}



std::unique_ptr<AppExprAST> ParseAppExpr(){
  lexer.getNextToken();//consume app
  std::string fname = lexer.getId();
  lexer.getNextToken();//consume funcname
  std::vector<std::unique_ptr<VariableExprAST>> args;
  while(lexer.getCurToken() != tok_semicolon){
    args.push_back(ParseVarExpr());
  }
  return std::make_unique<AppExprAST>(fname,std::move(args));
}

std::unique_ptr<CallExprAST> ParseCallExpr(){
  std::string fname = lexer.getId();
  lexer.getNextToken();//consume funcname
  std::vector<std::unique_ptr<VariableExprAST>> args;
  while(lexer.getCurToken() != tok_semicolon){

    args.push_back(ParseVarExpr());
  }
  return std::make_unique<CallExprAST>(fname,std::move(args));
}

std::unique_ptr<CtorExprAST> ParseCtorExpr(){
  int Tag = std::stoi(lexer.getId().substr(5).c_str());
  lexer.getNextToken();//consume ctor_x
  lexer.getNextToken();//consume '['
  lexer.getNextToken();//consume ConstrName
  lexer.getNextToken();//consume ']'
  std::vector<std::unique_ptr<VariableExprAST>> Args;
  while(lexer.getCurToken() != tok_semicolon){
    Args.push_back(ParseVarExpr());
  }
  return std::make_unique<CtorExprAST>(Tag,std::move(Args));
}

std::unique_ptr<ProjExprAST> ParseProjExpr(){

  lexer.getNextToken();//consume "proj"
  lexer.getNextToken();//consume '['
  int i = lexer.getValue();
  lexer.getNextToken();//consume Numval
  lexer.getNextToken();//consume ']'

  return std::make_unique<ProjExprAST>(i,std::move(ParseVarExpr()));
}
 std::unique_ptr<ExprAST> ParseExpression(){
   if(lexer.getCurToken() == tok_id){
     return std::move(ParseCallExpr());
   }
   if(lexer.getCurToken() == tok_app){
     return std::move(ParseAppExpr());
   }
   else if (lexer.getCurToken() == tok_lit) {
     return std::move(ParseNumberExpr());
   }
   else if (lexer.getCurToken() == tok_ctor) {
     return std::move(ParseCtorExpr());
   }
   else if (lexer.getCurToken() == tok_proj) {

     return std::move(ParseProjExpr());
   }
   else {
     std::cout << "Invalid Expression, nullptr" << std::endl;
     return nullptr;
   }
}


//let var := expression
 std::unique_ptr<LetStmtAST> ParseLetStmt(){
  lexer.getNextToken();//consume let
  std::string var = lexer.getId();
  lexer.getNextToken();lexer.getNextToken(); //consume var name :
  VarType t = ParseType();
  lexer.getNextToken();lexer.getNextToken();//consume  :=
  auto expr = ParseExpression();
  lexer.getNextToken();//consume ';'

  return std::make_unique<LetStmtAST>(lexer.getLoc(),var,std::move(expr),t);
}


 std::unique_ptr<DirectRetStmtAST> ParseDirectRetStmt(){
  lexer.getNextToken();//consume ret
  std::string var = lexer.getId();
  lexer.getNextToken();//consume var
  return std::make_unique<DirectRetStmtAST>(lexer.getLoc(), var);
}

std::unique_ptr<CaseStmtAST> ParseCaseStmt(){
  lexer.getNextToken();//consume case
  std::string var = lexer.getId();
  std::vector<std::unique_ptr<FBodyAST>> bodies;
  lexer.getNextToken();//consume var name
  lexer.getNextToken();//consume :
  lexer.getNextToken();//consume type
  lexer.getNextToken();//consume of

  while(lexer.getCurToken() == tok_id){
    lexer.getNextToken();//consume branch
    lexer.getNextToken();lexer.getNextToken();lexer.getNextToken();//consume ->
    bodies.push_back(ParseFBody());
  }
  return std::make_unique<CaseStmtAST>(lexer.getLoc(),std::move(bodies),var);
}

 std::unique_ptr<RetStmtAST> ParseRetStmt(){
  if(lexer.getCurToken() == tok_ret){
    return std::move(ParseDirectRetStmt());
  }
  else if(lexer.getCurToken() == tok_case){
    return std::move(ParseCaseStmt());
  }
  else {
    std::cout << lexer.getCurToken() << std::endl;
    std::cout << "Error in return statement, nullptr" << std::endl;
    return nullptr;
  }
}

 std::unique_ptr<FBodyAST> ParseFBody(){
  std::vector<std::unique_ptr<LetStmtAST>> stmts;
  while(lexer.getCurToken() == tok_let){
    stmts.push_back(ParseLetStmt());
  }
  return std::make_unique<FBodyAST>(std::move(stmts),std::move(ParseRetStmt()));
}

 std::unique_ptr<FunctionAST> ParseFunction(){
  std::vector<std::unique_ptr<VariableExprAST>> Args;
  std::vector<VarType> ArgTypes;
  lexer.getNextToken();//eat def
  std::string FName = lexer.getId();
  if(FName == "main"){
    FName = "_lean_main";
  }
  while(true){
    lexer.getNextToken(); //eat fname or ) depending on first or later iteration
    if(lexer.getCurToken() != '('){
      break;
    }
    lexer.getNextToken(); //eat '('
    Args.push_back(ParseVarExpr());
    lexer.getNextToken(); //consume :
    ArgTypes.push_back(ParseType());

  }
  lexer.getNextToken(); // consume :
  VarType retType = ParseType();
  lexer.getNextToken();lexer.getNextToken(); //eat :=
  auto FBody = ParseFBody();
  return std::make_unique<FunctionAST>
        (lexer.getLoc(),FName, std::move(Args),
         std::move(FBody), std::move(ArgTypes), retType);
}


public:
Parser(Lexer &lexer) : lexer(lexer){}

std::unique_ptr<ModuleAST> parse(){
  lexer.getNextToken();//get rid of start of file token
  std::vector<std::unique_ptr<FunctionAST>> FList;
  while(true){
    switch (lexer.getCurToken()){
      case tok_eof:
        return std::make_unique<ModuleAST>(std::move(FList));
      case tok_def:
        FList.push_back(ParseFunction());
        break;
      default:
        std::cout << "unexpected token: " << lexer.getId() << "[" << lexer.getCurToken() << "]"  << std::endl;
        lexer.getNextToken();
        break;
    }
  }
}
};//class Parser
}//namespace lambdapure
