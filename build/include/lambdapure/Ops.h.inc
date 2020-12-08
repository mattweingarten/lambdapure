/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Declarations                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES

class AllocCtorOp;
class AppOp;
class BoxOp;
class CallOp;
class CaseOp;
class ConstructorOp;
class CtorSetOp;
class DecOp;
class IncOp;
class IntegerConstOp;
class PapOp;
class ProjectionOp;
class ResetOp;
class ReturnOp;
class ReuseAllocCtorOp;
class ReuseConstructorOp;
class TagGetOp;
class TagSetOp;
class UnboxOp;

//===----------------------------------------------------------------------===//
// lambdapure::AllocCtorOp declarations
//===----------------------------------------------------------------------===//

class AllocCtorOpOperandAdaptor {
public:
  AllocCtorOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  AllocCtorOpOperandAdaptor(AllocCtorOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  IntegerAttr tag();
  IntegerAttr size();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class AllocCtorOp : public Op<AllocCtorOp, OpTrait::ZeroRegion, OpTrait::OneResult, OpTrait::ZeroSuccessor, OpTrait::ZeroOperands> {
public:
  using Op::Op;
  using OperandAdaptor = AllocCtorOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  IntegerAttr tagAttr();
  APInt tag();
  IntegerAttr sizeAttr();
  APInt size();
  void tagAttr(IntegerAttr attr);
  void sizeAttr(IntegerAttr attr);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, IntegerAttr tag, IntegerAttr size);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr tag, IntegerAttr size);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, APInt tag, APInt size);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt tag, APInt size);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
};

//===----------------------------------------------------------------------===//
// lambdapure::AppOp declarations
//===----------------------------------------------------------------------===//

class AppOpOperandAdaptor {
public:
  AppOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  AppOpOperandAdaptor(AppOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  Value callee();
  ValueRange operands();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class AppOp : public Op<AppOp, OpTrait::ZeroRegion, OpTrait::OneResult, OpTrait::ZeroSuccessor, OpTrait::AtLeastNOperands<1>::Impl> {
public:
  using Op::Op;
  using OperandAdaptor = AppOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  Value callee();
  Operation::operand_range operands();
  ::mlir::MutableOperandRange calleeMutable();
  ::mlir::MutableOperandRange operandsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  static void build(OpBuilder &builder, OperationState &state, Value func, ArrayRef<Value> args, Type ty);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, Value callee, ValueRange operands);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, Value callee, ValueRange operands);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
};

//===----------------------------------------------------------------------===//
// lambdapure::BoxOp declarations
//===----------------------------------------------------------------------===//

class BoxOpOperandAdaptor {
public:
  BoxOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  BoxOpOperandAdaptor(BoxOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  IntegerAttr value();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class BoxOp : public Op<BoxOp, OpTrait::ZeroRegion, OpTrait::OneResult, OpTrait::ZeroSuccessor, OpTrait::ZeroOperands, MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using OperandAdaptor = BoxOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  IntegerAttr valueAttr();
  APInt value();
  void valueAttr(IntegerAttr attr);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, IntegerAttr value);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr value);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, APInt value);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt value);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
  void getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects);
};

//===----------------------------------------------------------------------===//
// lambdapure::CallOp declarations
//===----------------------------------------------------------------------===//

class CallOpOperandAdaptor {
public:
  CallOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  CallOpOperandAdaptor(CallOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  ValueRange inputs();
  FlatSymbolRefAttr callee();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class CallOp : public Op<CallOp, OpTrait::ZeroRegion, OpTrait::OneResult, OpTrait::ZeroSuccessor, OpTrait::VariadicOperands> {
public:
  using Op::Op;
  using OperandAdaptor = CallOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  Operation::operand_range inputs();
  ::mlir::MutableOperandRange inputsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  FlatSymbolRefAttr calleeAttr();
  StringRef callee();
  void calleeAttr(FlatSymbolRefAttr attr);
  static void build(OpBuilder &builder, OperationState &state, StringRef callee, ArrayRef<Value> args,Type ty);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, FlatSymbolRefAttr callee, ValueRange inputs);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, FlatSymbolRefAttr callee, ValueRange inputs);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, StringRef callee, ValueRange inputs);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, StringRef callee, ValueRange inputs);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
};

//===----------------------------------------------------------------------===//
// lambdapure::CaseOp declarations
//===----------------------------------------------------------------------===//

class CaseOpOperandAdaptor {
public:
  CaseOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  CaseOpOperandAdaptor(CaseOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  Value operand();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class CaseOp : public Op<CaseOp, OpTrait::VariadicRegions, OpTrait::ZeroResult, OpTrait::ZeroSuccessor, OpTrait::OneOperand, MemoryEffectOpInterface::Trait, OpTrait::IsTerminator> {
public:
  using Op::Op;
  using OperandAdaptor = CaseOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  Value operand();
  ::mlir::MutableOperandRange operandMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  MutableArrayRef<Region> region();
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Value operand, unsigned regionCount);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, Value operand, unsigned regionCount);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes, unsigned numRegions);
  LogicalResult verify();
  void getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects);
};

//===----------------------------------------------------------------------===//
// lambdapure::ConstructorOp declarations
//===----------------------------------------------------------------------===//

class ConstructorOpOperandAdaptor {
public:
  ConstructorOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  ConstructorOpOperandAdaptor(ConstructorOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  ValueRange operands();
  IntegerAttr tag();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class ConstructorOp : public Op<ConstructorOp, OpTrait::ZeroRegion, OpTrait::OneResult, OpTrait::ZeroSuccessor, OpTrait::VariadicOperands> {
public:
  using Op::Op;
  using OperandAdaptor = ConstructorOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  Operation::operand_range operands();
  ::mlir::MutableOperandRange operandsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  IntegerAttr tagAttr();
  APInt tag();
  void tagAttr(IntegerAttr attr);
  static void build(OpBuilder &builder,OperationState &state,int tag, ArrayRef<Value> operands, mlir::Type ty);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, IntegerAttr tag, ValueRange operands);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr tag, ValueRange operands);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, APInt tag, ValueRange operands);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt tag, ValueRange operands);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
};

//===----------------------------------------------------------------------===//
// lambdapure::CtorSetOp declarations
//===----------------------------------------------------------------------===//

class CtorSetOpOperandAdaptor {
public:
  CtorSetOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  CtorSetOpOperandAdaptor(CtorSetOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  Value ctor_obj();
  Value set_obj();
  IntegerAttr index();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class CtorSetOp : public Op<CtorSetOp, OpTrait::ZeroRegion, OpTrait::ZeroResult, OpTrait::ZeroSuccessor, OpTrait::NOperands<2>::Impl> {
public:
  using Op::Op;
  using OperandAdaptor = CtorSetOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  Value ctor_obj();
  Value set_obj();
  ::mlir::MutableOperandRange ctor_objMutable();
  ::mlir::MutableOperandRange set_objMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  IntegerAttr indexAttr();
  APInt index();
  void indexAttr(IntegerAttr attr);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, IntegerAttr index, Value ctor_obj, Value set_obj);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr index, Value ctor_obj, Value set_obj);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, APInt index, Value ctor_obj, Value set_obj);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt index, Value ctor_obj, Value set_obj);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
};

//===----------------------------------------------------------------------===//
// lambdapure::DecOp declarations
//===----------------------------------------------------------------------===//

class DecOpOperandAdaptor {
public:
  DecOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  DecOpOperandAdaptor(DecOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  Value object();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class DecOp : public Op<DecOp, OpTrait::ZeroRegion, OpTrait::ZeroResult, OpTrait::ZeroSuccessor, OpTrait::OneOperand> {
public:
  using Op::Op;
  using OperandAdaptor = DecOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  Value object();
  ::mlir::MutableOperandRange objectMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Value object);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, Value object);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
};

//===----------------------------------------------------------------------===//
// lambdapure::IncOp declarations
//===----------------------------------------------------------------------===//

class IncOpOperandAdaptor {
public:
  IncOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  IncOpOperandAdaptor(IncOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  Value object();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class IncOp : public Op<IncOp, OpTrait::ZeroRegion, OpTrait::ZeroResult, OpTrait::ZeroSuccessor, OpTrait::OneOperand> {
public:
  using Op::Op;
  using OperandAdaptor = IncOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  Value object();
  ::mlir::MutableOperandRange objectMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Value object);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, Value object);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
};

//===----------------------------------------------------------------------===//
// lambdapure::IntegerConstOp declarations
//===----------------------------------------------------------------------===//

class IntegerConstOpOperandAdaptor {
public:
  IntegerConstOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  IntegerConstOpOperandAdaptor(IntegerConstOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  IntegerAttr value();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class IntegerConstOp : public Op<IntegerConstOp, OpTrait::ZeroRegion, OpTrait::OneResult, OpTrait::ZeroSuccessor, OpTrait::ZeroOperands, MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using OperandAdaptor = IntegerConstOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  IntegerAttr valueAttr();
  APInt value();
  void valueAttr(IntegerAttr attr);
  static void build(OpBuilder &builder, OperationState &state, int value);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, IntegerAttr value);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr value);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, APInt value);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt value);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
  void getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects);
};

//===----------------------------------------------------------------------===//
// lambdapure::PapOp declarations
//===----------------------------------------------------------------------===//

class PapOpOperandAdaptor {
public:
  PapOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  PapOpOperandAdaptor(PapOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  ValueRange operands();
  FlatSymbolRefAttr callee();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class PapOp : public Op<PapOp, OpTrait::ZeroRegion, OpTrait::OneResult, OpTrait::ZeroSuccessor, OpTrait::VariadicOperands> {
public:
  using Op::Op;
  using OperandAdaptor = PapOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  Operation::operand_range operands();
  ::mlir::MutableOperandRange operandsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  FlatSymbolRefAttr calleeAttr();
  StringRef callee();
  void calleeAttr(FlatSymbolRefAttr attr);
  static void build(OpBuilder &builder, OperationState &state, StringRef callee, ArrayRef<Value> args);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, FlatSymbolRefAttr callee, ValueRange operands);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, FlatSymbolRefAttr callee, ValueRange operands);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, StringRef callee, ValueRange operands);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, StringRef callee, ValueRange operands);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
};

//===----------------------------------------------------------------------===//
// lambdapure::ProjectionOp declarations
//===----------------------------------------------------------------------===//

class ProjectionOpOperandAdaptor {
public:
  ProjectionOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  ProjectionOpOperandAdaptor(ProjectionOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  Value operand();
  IntegerAttr index();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class ProjectionOp : public Op<ProjectionOp, OpTrait::ZeroRegion, OpTrait::OneResult, OpTrait::ZeroSuccessor, OpTrait::OneOperand, MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using OperandAdaptor = ProjectionOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  Value operand();
  ::mlir::MutableOperandRange operandMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  IntegerAttr indexAttr();
  APInt index();
  void indexAttr(IntegerAttr attr);
  static void build(OpBuilder &builder,OperationState &state,int index, mlir::Value operand, mlir::Type ty);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, IntegerAttr index, Value operand);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr index, Value operand);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, APInt index, Value operand);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt index, Value operand);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
  void getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects);
};

//===----------------------------------------------------------------------===//
// lambdapure::ResetOp declarations
//===----------------------------------------------------------------------===//

class ResetOpOperandAdaptor {
public:
  ResetOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  ResetOpOperandAdaptor(ResetOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  Value object();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class ResetOp : public Op<ResetOp, OpTrait::VariadicRegions, OpTrait::ZeroResult, OpTrait::ZeroSuccessor, OpTrait::OneOperand, MemoryEffectOpInterface::Trait, OpTrait::IsTerminator> {
public:
  using Op::Op;
  using OperandAdaptor = ResetOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  Value object();
  ::mlir::MutableOperandRange objectMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  MutableArrayRef<Region> region();
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Value object, unsigned regionCount);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, Value object, unsigned regionCount);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes, unsigned numRegions);
  LogicalResult verify();
  void getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects);
};

//===----------------------------------------------------------------------===//
// lambdapure::ReturnOp declarations
//===----------------------------------------------------------------------===//

class ReturnOpOperandAdaptor {
public:
  ReturnOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  ReturnOpOperandAdaptor(ReturnOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  Value input();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class ReturnOp : public Op<ReturnOp, OpTrait::ZeroRegion, OpTrait::ZeroResult, OpTrait::ZeroSuccessor, OpTrait::OneOperand, MemoryEffectOpInterface::Trait, OpTrait::IsTerminator> {
public:
  using Op::Op;
  using OperandAdaptor = ReturnOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  Value input();
  ::mlir::MutableOperandRange inputMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Value input);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, Value input);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
  void getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects);
};

//===----------------------------------------------------------------------===//
// lambdapure::ReuseAllocCtorOp declarations
//===----------------------------------------------------------------------===//

class ReuseAllocCtorOpOperandAdaptor {
public:
  ReuseAllocCtorOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  ReuseAllocCtorOpOperandAdaptor(ReuseAllocCtorOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  Value object();
  IntegerAttr tag();
  IntegerAttr size();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class ReuseAllocCtorOp : public Op<ReuseAllocCtorOp, OpTrait::ZeroRegion, OpTrait::OneResult, OpTrait::ZeroSuccessor, OpTrait::OneOperand> {
public:
  using Op::Op;
  using OperandAdaptor = ReuseAllocCtorOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  Value object();
  ::mlir::MutableOperandRange objectMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  IntegerAttr tagAttr();
  APInt tag();
  IntegerAttr sizeAttr();
  APInt size();
  void tagAttr(IntegerAttr attr);
  void sizeAttr(IntegerAttr attr);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, IntegerAttr tag, IntegerAttr size, Value object);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr tag, IntegerAttr size, Value object);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, APInt tag, APInt size, Value object);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt tag, APInt size, Value object);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
};

//===----------------------------------------------------------------------===//
// lambdapure::ReuseConstructorOp declarations
//===----------------------------------------------------------------------===//

class ReuseConstructorOpOperandAdaptor {
public:
  ReuseConstructorOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  ReuseConstructorOpOperandAdaptor(ReuseConstructorOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  ValueRange operands();
  IntegerAttr tag();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class ReuseConstructorOp : public Op<ReuseConstructorOp, OpTrait::ZeroRegion, OpTrait::OneResult, OpTrait::ZeroSuccessor, OpTrait::VariadicOperands> {
public:
  using Op::Op;
  using OperandAdaptor = ReuseConstructorOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  Operation::operand_range operands();
  ::mlir::MutableOperandRange operandsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  IntegerAttr tagAttr();
  APInt tag();
  void tagAttr(IntegerAttr attr);
  static void build(OpBuilder &builder,OperationState &state,int tag, ArrayRef<Value> operands);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, IntegerAttr tag, ValueRange operands);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr tag, ValueRange operands);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, APInt tag, ValueRange operands);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt tag, ValueRange operands);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
};

//===----------------------------------------------------------------------===//
// lambdapure::TagGetOp declarations
//===----------------------------------------------------------------------===//

class TagGetOpOperandAdaptor {
public:
  TagGetOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  TagGetOpOperandAdaptor(TagGetOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  Value object();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class TagGetOp : public Op<TagGetOp, OpTrait::ZeroRegion, OpTrait::OneResult, OpTrait::ZeroSuccessor, OpTrait::OneOperand, MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using OperandAdaptor = TagGetOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  Value object();
  ::mlir::MutableOperandRange objectMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, Value object);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, Value object);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
  void getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects);
};

//===----------------------------------------------------------------------===//
// lambdapure::TagSetOp declarations
//===----------------------------------------------------------------------===//

class TagSetOpOperandAdaptor {
public:
  TagSetOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  TagSetOpOperandAdaptor(TagSetOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  Value object();
  IntegerAttr tag();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class TagSetOp : public Op<TagSetOp, OpTrait::ZeroRegion, OpTrait::ZeroResult, OpTrait::ZeroSuccessor, OpTrait::OneOperand, MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using OperandAdaptor = TagSetOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  Value object();
  ::mlir::MutableOperandRange objectMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  IntegerAttr tagAttr();
  APInt tag();
  void tagAttr(IntegerAttr attr);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, IntegerAttr tag, Value object);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr tag, Value object);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, APInt tag, Value object);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt tag, Value object);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
  void getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects);
};

//===----------------------------------------------------------------------===//
// lambdapure::UnboxOp declarations
//===----------------------------------------------------------------------===//

class UnboxOpOperandAdaptor {
public:
  UnboxOpOperandAdaptor(ValueRange values, DictionaryAttr attrs = nullptr);
  UnboxOpOperandAdaptor(UnboxOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ValueRange getODSOperands(unsigned index);
  Value object();

private:
  ValueRange odsOperands;
  DictionaryAttr odsAttrs;
};
class UnboxOp : public Op<UnboxOp, OpTrait::ZeroRegion, OpTrait::OneResult, OpTrait::ZeroSuccessor, OpTrait::OneOperand, MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using OperandAdaptor = UnboxOpOperandAdaptor;
  static StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  Operation::operand_range getODSOperands(unsigned index);
  Value object();
  ::mlir::MutableOperandRange objectMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  Operation::result_range getODSResults(unsigned index);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, Value object);
  static void build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, Value object);
  static void build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes);
  LogicalResult verify();
  void getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects);
};

#endif  // GET_OP_CLASSES

