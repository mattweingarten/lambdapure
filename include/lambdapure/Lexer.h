#ifndef LAMBDAPURE_LEXER_H_
#define LAMBDAPURE_LEXER_H_
#include "llvm/ADT/StringRef.h"
#include <iostream>


namespace lambdapure{

struct Location {
  std::shared_ptr<std::string> file;
  int line;
  int col;
};


enum Token : int{
  tok_eof = 0,

  //symbols
  tok_semicolon = 59 , // ';'
  tok_colon =  58 , // ':'
  tok_apostrophe = 39,// '
  //keywords
  tok_def = -2, //def
  tok_let = -3, //let
  tok_ret = -4, //ret
  tok_case = -5, //case
  tok_app = -6, //app
  tok_ctor = -7, //ctor
  tok_proj = -8, //proj
  //....
  //values
  tok_id = -100, //identifier
  tok_lit = -101 //literal number
};


class Lexer {
private:
  //buffer
  llvm::StringRef buffer;
  int bufferIndex = 0;
  //Location
  Location lastLocation;
  int curLine = 1;
  int curCol = 1;

  //tokens
  std::string identifierStr;
  double numVal = 0;
  Token curTok = tok_eof;
  Token lastChar = Token(' ');

  int getNextChar(){

    if(bufferIndex >= buffer.size()){
      return EOF;
    }
    else{
      curCol++;
      int res = buffer.begin()[bufferIndex];
      if(res == '\n'){
        curCol = 1;
        curLine++;
      }
      bufferIndex++;
      return res;
    }

  }

  Token getTok(){
    while (isspace(lastChar)){
      lastChar = Token(getNextChar());
    }

    lastLocation.line = curLine;
    lastLocation.col = curCol;
    if (isalpha(lastChar) || lastChar == '_') { //if this is [a-zA-Z][a-zA-Z0-9_]
      identifierStr = lastChar;
      lastChar = Token(getNextChar());

      while (isalnum(lastChar) || lastChar == '_' || lastChar == '.' || lastChar == '\''){ //[a-zA-Z][a-zA-Z0-9_.]
        if(lastChar == '\''){ //replace apostrophe with _prime, c cant have it in function names
          identifierStr += "_prime_";
        }
        else if(lastChar == '.'){
          identifierStr += "_dot_";
        }
        else {
          identifierStr += lastChar;
        }
        lastChar = Token(getNextChar());
      };
      if (identifierStr == "def")
        return tok_def;
      if (identifierStr == "let")
        return tok_let;
      if(identifierStr == "ret")
        return tok_ret;
      if(identifierStr == "case")
        return tok_case;
      if(identifierStr == "app")
        return tok_app;
      if(identifierStr == "proj")
        return tok_proj;
      if(identifierStr.find("ctor_") != std::string::npos)
        return tok_ctor;

      return tok_id;
    }


    if (isdigit(lastChar)) { // Number(no floats): [0-9]*
      std::string NumStr;
      do {
        NumStr += lastChar;
        lastChar = Token(getNextChar());
      }while(isdigit(lastChar));
      numVal = std::stoi(NumStr.c_str());
      return tok_lit;
   }





   if (lastChar == EOF)
     return tok_eof;
   //ending case: return characters in single token(ascii)
   Token ThisChar = Token(lastChar);
   lastChar = Token(getNextChar());
   return ThisChar;
  }

// std::string curLineBuffer = "\n";

public:
  Lexer(std::string filename,llvm::StringRef buffer)
      : lastLocation({std::make_shared<std::string>(std::move(filename)),1,1}),
        buffer(buffer) {}


  Token getCurToken(){return curTok;}
  Token getNextToken() {return curTok = getTok();}
  void consume(Token tok) {
    assert(tok == curTok && "consume Token mismatch expectation");
    getNextToken();
  }

  std::string getId() {
    return identifierStr;
  }

  double getValue() {
    assert(curTok == tok_lit);
    return numVal;
  }

  Location getLoc(){return lastLocation;}
  int getLine(){return curLine;}
  int getCol(){return curCol;}


};
}//namespace lambdapure


#endif //LAMBDAPURE_LEXER_H_
