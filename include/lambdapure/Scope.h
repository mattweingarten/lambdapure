#include <map>
#include <iterator>
#include <iostream>

namespace lambdapure{

class Mapping{
public:
  std::string var;
  mlir::Value val;
  mlir::Type ty;
  Mapping(std::string var, mlir::Value val,mlir::Type ty) :
          var(var), val(val), ty(ty) {}
};

class ScopeTable{
  private:
    std::vector<Mapping *> curr;
    std::vector<Mapping * > prev;


    bool exist(std::string var){
      for(auto p: curr){
          if(p -> var.compare(var) == 0) {return true;}
        }
        return false;
      }
  public:
    void scope(){
      for(auto p : curr){
        prev.push_back(p);
      }
    }
    void descope(){
      curr.clear();
      for(auto p : prev){
        curr.push_back(p);
      }
      prev.clear();
    }
    mlir::LogicalResult declare(llvm::StringRef var, mlir::Value val,mlir::Type ty){
      return declare(var.str(),val,ty);
    }

    mlir::LogicalResult declare(std::string var, mlir::Value val,mlir::Type ty ){
      if(exist(var)){ return mlir::failure();}
      else{curr.push_back(new Mapping(var,val,ty));}
      return mlir::success();
    }
    mlir::Value lookup(llvm::StringRef var){ return lookup(var.str());}
    mlir::Value lookup(std::string var){
      for(auto p: curr) {
        if(p -> var.compare(var) == 0){
          return p -> val;
        }
       }
       return nullptr;
    }

    mlir::Type lookupType(llvm::StringRef var){ return lookupType(var.str());}
    mlir::Type lookupType(std::string var){
      for(auto p:curr){
        if(p -> var.compare(var) == 0 ){
          return p -> ty;
        }
      }
    }
    void print(){
      std::cout << "-----SymbolTable-----" << std::endl;
      for(auto p: curr){
        std::cout << p -> var << std::endl;
      }
      std::cout << "---------------------" << std::endl;
    }



};//class ScopeTable
}//namespace lambdpure
