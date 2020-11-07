#ifndef LAMBDAPURE_AST_H_
#define LAMBDAPURE_AST_H_
#include <map>
#include <utility>
#include <vector>
#include <memory>
#include <iostream>
#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/StringRef.h"
#include "lambdapure/lexer.h"
// #include "llvm/Support/Casting.h"

namespace lambdapure{

static std::string offset = "";
///ConstAST - Const class for applied function

// class ConstAST{
//   public:
// };
///Expr class - expression can be either constant application ()

enum VarType {object,u64,u32,u16,u8};
std::string stringOfType(VarType t);
std::string stringOfType(std::vector<VarType> ts);
std::string stringOfType(std::vector<VarType> ts, VarType t);


class ExprAST{

public:
  enum Kind{
    NumberExpr,
    VarExpr,
    AppExpr,
    CallExpr,
    ProjExpr,
    CtorExpr,
  };

  ExprAST(Kind kind) : kind(kind) {}
    virtual ~ExprAST() = default;
    virtual void print() = 0;


  Kind getKind() const {return kind;}

private:
Kind kind;
};

/// Numeral literal expression
class NumberExprAST : public ExprAST {
  int Val;

public:
  NumberExprAST(double Val) : ExprAST(NumberExpr), Val(Val) {}
  void print();
  int getValue(){return Val;}
  /// LLVM style RTTI
  static bool classof(const ExprAST *c) { return c->getKind() == NumberExpr; }
};


//Variable expression
class VariableExprAST : public ExprAST {
  std::string Name;

public:
  VariableExprAST(const std::string &Name) :ExprAST(VarExpr), Name(Name) {}
  std::string getName(){return Name;}
  void print();
  static bool classof(const ExprAST *c) { return c->getKind() == VarExpr; }
};

// AppAST -indirect function call
class AppExprAST : public ExprAST{
  std::string FName;
  std::vector<std::unique_ptr<VariableExprAST>> Args;

  public:
       AppExprAST(const std::string &FName,
              std::vector<std::unique_ptr<VariableExprAST>> Args)
        :ExprAST(AppExpr), FName(FName), Args(std::move(Args)) {}

  void print();
  std::string getFName() {return FName;}
  llvm::ArrayRef<std::unique_ptr<VariableExprAST>> getArgs(){return Args;}
  static bool classof(const ExprAST *c) { return c->getKind() == AppExpr; }
};


//direct function call
class CallExprAST : public ExprAST {
  std::string FName;
  std::vector<std::unique_ptr<VariableExprAST>> Args;

  public:
      CallExprAST(const std::string &FName,
               std::vector<std::unique_ptr<VariableExprAST>> Args)
         :ExprAST(CallExpr), FName(FName), Args(std::move(Args)) {}
  void print();
  std::string getFName(){return FName;}
  llvm::ArrayRef<std::unique_ptr<VariableExprAST>> getArgs(){return Args;}
  static bool classof(const ExprAST *c) { return c->getKind() == CallExpr; }
};

class CtorExprAST : public ExprAST {
    int Tag;
    std::vector<std::unique_ptr<VariableExprAST>> Args;

    public:

      CtorExprAST(int Tag,
             std::vector<std::unique_ptr<VariableExprAST>> Args)
            : ExprAST(CtorExpr),Tag(Tag), Args(std::move(Args)) {}
    void print();
    int getTag(){return Tag;}
    llvm::ArrayRef<std::unique_ptr<VariableExprAST>> getArgs(){return Args;}
    static bool classof(const ExprAST *c) { return c->getKind() == CtorExpr; }
};

class ProjExprAST : public ExprAST {
  int I;
  std::unique_ptr<VariableExprAST> Var;

  public:

    ProjExprAST(int i, std::unique_ptr<VariableExprAST> Var)
              : ExprAST(ProjExpr), I(i), Var(std::move(Var)) {}
  void print();
  int getIndex(){return I;}
  VariableExprAST *getVar(){return Var.get();}
  std::string getVarName(){return Var -> getName();}
  static bool classof(const ExprAST *c) { return c->getKind() == ProjExpr; }
};


///StatementAST - statment can be either let = expr , ret variable, or case x of F
class StmtAST{
public:
    virtual ~StmtAST() = default;
    virtual void print() = 0;
    Location getLoc(){return location;}
    StmtAST(Location location) : location(location){}
private:
  Location location;
};



class LetStmtAST: public StmtAST{
  std::string Var;
  std::unique_ptr<ExprAST> Rhs;
  VarType Vtype;

public:
    LetStmtAST(
               Location location,
               const std::string Var,
               std::unique_ptr<ExprAST> Rhs,
               VarType Vtype
             ) : StmtAST(location), Var(Var), Rhs(std::move(Rhs)), Vtype(Vtype){}
   void print();
   std::string getName(){return Var;}
   VarType getVtype() {return Vtype;}
   ExprAST *getExpr(){return Rhs.get();}
};



class RetStmtAST : public StmtAST{

public:
    enum Kind{
      Direct,
      Case,
    };
    RetStmtAST(Kind Kind,Location Location) : StmtAST(Location), Kind(Kind){}
    virtual ~RetStmtAST() = default;
    virtual void print() = 0;
    Kind getKind() const {return Kind;}
private:
  Kind Kind;
};

class DirectRetStmtAST : public RetStmtAST{
  std::string Var;

  public:
    DirectRetStmtAST(Location location, const std::string &Var)
                    : RetStmtAST(Direct,location),Var(Var){}
  void print();
  std::string getVar(){return Var;}
  static bool classof(const RetStmtAST *c) { return c->getKind() == Direct; }
};




class FBodyAST{
  std::vector<std::unique_ptr<LetStmtAST>> Stmts;
  std::unique_ptr<RetStmtAST> Ret;

public:
  FBodyAST(
          std::vector<std::unique_ptr<LetStmtAST>> Stmts,
          std::unique_ptr<RetStmtAST> Ret
        ) : Stmts(std::move(Stmts)), Ret(std::move(Ret)) {}

  void print();
  llvm::ArrayRef<std::unique_ptr<LetStmtAST>> getStmts(){return Stmts;}
  RetStmtAST* getRet(){Ret.get();}
};


class CaseStmtAST : public RetStmtAST{
  std::vector<std::unique_ptr<FBodyAST>> Bodies;
  std::string Var;
public:
  CaseStmtAST(
    Location location,
    std::vector<std::unique_ptr<FBodyAST>> Bodies,
    const std::string &Var ) :
      RetStmtAST(Case,location), Bodies(std::move(Bodies)), Var(Var) {}
    void print();
    std::string getVar(){return Var;}
    llvm::ArrayRef<std::unique_ptr<FBodyAST>> getBodies(){return Bodies;}
    static bool classof(const RetStmtAST *c) { return c->getKind() == Case; }

};





class FunctionAST{
  Location location;
  std::string FName;
  std::vector<std::unique_ptr<VariableExprAST>> Args;
  std::unique_ptr<FBodyAST> FBody;
  std::vector<VarType> ArgTypes;
  VarType RetType;
public:
  FunctionAST(
    Location location,
    const std::string &FName,
    std::vector<std::unique_ptr<VariableExprAST>> Args,
    std::unique_ptr<FBodyAST> FBody,
    std::vector<VarType> ArgTypes,
    VarType RetType
  ) : location(location), FName(FName),Args(std::move(Args)), FBody(std::move(FBody)),
      ArgTypes(std::move(ArgTypes)), RetType(RetType){}

  std::string getName(){return FName;}
  Location getLoc(){return location;}
  llvm::ArrayRef<std::unique_ptr<VariableExprAST>> getArgs() { return Args; }
  FBodyAST *getFBody(){return FBody.get();}
  VarType getRetType(){return RetType;}
  llvm::ArrayRef<VarType> getArgTypes() {return ArgTypes;}
  void print();

};


class ModuleAST{
  std::vector<std::unique_ptr<FunctionAST>> FList;
public:
  ModuleAST(
    std::vector<std::unique_ptr<FunctionAST>> FList
  ) : FList(std::move(FList)){}

llvm::ArrayRef<std::unique_ptr<FunctionAST>> getFList(){
    return FList;
  }
  void print();
};

}//namespace lambdapure

#endif //LAMBDAPURE_AST_H_
