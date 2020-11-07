#include <map>
#include <utility>
#include <vector>
#include <memory>
#include <iostream>
#include<map>
// #include "mlir"

  class CppVarTable {
  public:
    std::string insert(mlir::Operation* op){
      std::string res = generateString();
      opMap.insert({op, res});
      return res;
    }

    std::string insert(mlir::Value val){
      vals.push_back(val);
      std::string res = generateString();

      strings_vector.push_back(res);
      return res;
    }

    std::string get(mlir::Value val){
      if(mlir::BlockArgument::classof(val)){
        mlir::BlockArgument arg = val.dyn_cast<mlir::BlockArgument>();
        int argNum = arg.getArgNumber();
        return "arg" + std::to_string(argNum);
      }else{
        for(int i = 0; i < vals.size();++i){
          if(vals.at(i) == val){
            std::string res = strings_vector.at(i);
            return res;
          }
        }
        return get(val.getDefiningOp());
      }
    }



    std::string get(mlir::Operation* op){
      std::map<mlir::Operation*,std::string>::iterator it;
      it = opMap.find(op);
      if(it == opMap.end()){
        assert(false && "tried to get undeclared varibale in VarTable");
        return nullptr;
      }else{
        return it -> second;
      }
    }

     // std::string getOrInsert(mlir::Operation* op){
     //   std::map<mlir::Operation*,std::string>::iterator it;
     //   it = opMap.find(op);
     //   if(it == opMap.end()){
     //
     //     std::string varName = generateString();
     //     opMap.insert({op,varName});
     //     return varName;
     //   }
     //   else {
     //     return it -> second;
     //   }
     // }

  void print(){
    std::cout << "Map " << std::endl << "---------------"  << std::endl;
    for(std::map<mlir::Operation*, std::string>::iterator it = opMap.begin();
        it != opMap.end(); ++ it){
          std::cout << "---" << std::endl;
          it -> first -> dump();
          std::cout << it -> second << std::endl;
          std::cout << "---" << std::endl;
        }
    std::cout << "---------------"  << std::endl;
  }
  private:
    int varNum = 0;
    std::map<mlir::Operation*,std::string> opMap;
    std::vector<mlir::Value> vals;
    std::vector<std::string> strings_vector;
    std::string generateString(){
      varNum++;
      return "x_" + std::to_string(varNum);
    }
};
