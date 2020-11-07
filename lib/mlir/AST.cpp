#include "lambdapure/AST.h"

namespace lambdapure{

  //PRINTER Functions
  //====================

  void FBodyAST::print(){
    offset = offset + " ";
    for(int i = 0; i < Stmts.size(); ++i){
      std::cout << offset;
      Stmts.at(i) -> print();
    }
    std::cout << offset;
    Ret -> print();
  }

  void ModuleAST::print(){
    std::cout << "-------------------AST-----------------------" << std::endl;
    std::cout << "---------------------------------------------" << std::endl <<std::endl;
    for(int i = 0;i < FList.size();++i){
      FList.at(i) -> print();
    }
    std::cout <<  "--------------------------------------------" << std::endl;
  }

  void FunctionAST::print(){
    std::cout<< offset << FName << " (" << stringOfType(ArgTypes,RetType) <<") ";
    for(int i = 0; i < Args.size();++i){
      Args.at(i) -> print();
      std::cout << " ";
    }
    std::cout << std::endl << std::endl;
    FBody -> print();
    offset = "";
    std::cout << std::endl <<std::endl;
  }


  void DirectRetStmtAST::print(){
    std::cout << offset << "return " << Var << std::endl;
  }

  void LetStmtAST::print(){
    std::cout << offset <<  "Let " << stringOfType(Vtype) << " " << Var  << " = ";
    Rhs -> print();
    std::cout << std::endl;
  }

  void VariableExprAST::print(){
    std::cout<< Name;
  }

  void NumberExprAST::print(){
    std::cout << Val ;
  }
  void AppExprAST::print(){
    std::cout << "app " << FName ;
    for(int i = 0; i < Args.size(); ++i){
      std::cout  << " ";
      Args.at(i) -> print();
    }
  }

  void CallExprAST::print(){
    std::cout << "Call " << FName ;
    for(int i = 0; i < Args.size(); ++i){
      std::cout  << " ";
      Args.at(i) -> print();
    }
  }


  void CtorExprAST::print(){
    std::cout << "Ctor "<< Tag;
    for(int i = 0; i < Args.size(); ++i){
      std::cout  << " ";
      Args.at(i) -> print();
    }
  }
  void ProjExprAST::print(){
    std::cout << "Proj" << "[" << getIndex() << "] " << getVarName() << std::endl;
  }

  void CaseStmtAST::print(){
    std::cout << offset <<  "Case  on " << getVar() << " : " << std::endl;
    offset = offset + " ";
    for(int i = 0; i < Bodies.size(); ++i){
      Bodies.at(i) -> print();
      std::cout << std::endl;
    }
    offset = "";
  }

  std::string stringOfType(VarType t){
    if(t == object){
      return "object";
    }
    else{
      return "int";
    }
  }
  std::string stringOfType(std::vector<VarType> ts){
    std::string result = "";
    for(VarType t : ts ){
      result = result + stringOfType(t) + " -> ";
    }
    return result;
  }
  std::string stringOfType(std::vector<VarType> ts, VarType t){
    return stringOfType(ts) + "-> " + stringOfType(t);
  }
}//namespace lambdapure
