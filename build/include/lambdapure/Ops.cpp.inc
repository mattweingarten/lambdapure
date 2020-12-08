/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

lambdapure::AllocCtorOp,
lambdapure::AppOp,
lambdapure::BoxOp,
lambdapure::CallOp,
lambdapure::CaseOp,
lambdapure::ConstructorOp,
lambdapure::CtorSetOp,
lambdapure::DecOp,
lambdapure::IncOp,
lambdapure::IntegerConstOp,
lambdapure::PapOp,
lambdapure::ProjectionOp,
lambdapure::ResetOp,
lambdapure::ReturnOp,
lambdapure::ReuseAllocCtorOp,
lambdapure::ReuseConstructorOp,
lambdapure::TagGetOp,
lambdapure::TagSetOp,
lambdapure::UnboxOp
#endif  // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// lambdapure::AllocCtorOp definitions
//===----------------------------------------------------------------------===//

AllocCtorOpOperandAdaptor::AllocCtorOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

AllocCtorOpOperandAdaptor::AllocCtorOpOperandAdaptor(AllocCtorOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> AllocCtorOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

ValueRange AllocCtorOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

IntegerAttr AllocCtorOpOperandAdaptor::tag() {
  assert(odsAttrs && "no attributes when constructing adapter");
  IntegerAttr attr = odsAttrs.get("tag").cast<IntegerAttr>();
  return attr;
}

IntegerAttr AllocCtorOpOperandAdaptor::size() {
  assert(odsAttrs && "no attributes when constructing adapter");
  IntegerAttr attr = odsAttrs.get("size").cast<IntegerAttr>();
  return attr;
}

StringRef AllocCtorOp::getOperationName() {
  return "lambdapure.AllocCtorOp";
}

std::pair<unsigned, unsigned> AllocCtorOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::operand_range AllocCtorOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

std::pair<unsigned, unsigned> AllocCtorOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range AllocCtorOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

IntegerAttr AllocCtorOp::tagAttr() {
  return this->getAttr("tag").cast<IntegerAttr>();
}

APInt AllocCtorOp::tag() {
  auto attr = tagAttr();
  return attr.getValue();
}

IntegerAttr AllocCtorOp::sizeAttr() {
  return this->getAttr("size").cast<IntegerAttr>();
}

APInt AllocCtorOp::size() {
  auto attr = sizeAttr();
  return attr.getValue();
}

void AllocCtorOp::tagAttr(IntegerAttr attr) {
  this->getOperation()->setAttr("tag", attr);
}

void AllocCtorOp::sizeAttr(IntegerAttr attr) {
  this->getOperation()->setAttr("size", attr);
}

void AllocCtorOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, IntegerAttr tag, IntegerAttr size) {
  odsState.addAttribute("tag", tag);
  odsState.addAttribute("size", size);
  odsState.addTypes(resultType0);
}

void AllocCtorOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr tag, IntegerAttr size) {
  odsState.addAttribute("tag", tag);
  odsState.addAttribute("size", size);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void AllocCtorOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, APInt tag, APInt size) {
  odsState.addAttribute("tag", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), tag));
  odsState.addAttribute("size", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), size));
  odsState.addTypes(resultType0);
}

void AllocCtorOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt tag, APInt size) {
  odsState.addAttribute("tag", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), tag));
  odsState.addAttribute("size", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), size));
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void AllocCtorOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult AllocCtorOp::verify() {
  auto tblgen_tag = this->getAttr("tag");
  if (!tblgen_tag) return emitOpError("requires attribute 'tag'");
  {
    if (!(((tblgen_tag.isa<IntegerAttr>())) && ((tblgen_tag.cast<IntegerAttr>().getType().isSignlessInteger(64))))) return emitOpError("attribute 'tag' failed to satisfy constraint: 64-bit signless integer attribute");
  }
  auto tblgen_size = this->getAttr("size");
  if (!tblgen_size) return emitOpError("requires attribute 'size'");
  {
    if (!(((tblgen_size.isa<IntegerAttr>())) && ((tblgen_size.cast<IntegerAttr>().getType().isSignlessInteger(64))))) return emitOpError("attribute 'size' failed to satisfy constraint: 64-bit signless integer attribute");
  }
  {
    unsigned index = 0; (void)index;
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("result #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  return mlir::success();
}


//===----------------------------------------------------------------------===//
// lambdapure::AppOp definitions
//===----------------------------------------------------------------------===//

AppOpOperandAdaptor::AppOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

AppOpOperandAdaptor::AppOpOperandAdaptor(AppOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> AppOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperands.size() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

ValueRange AppOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

Value AppOpOperandAdaptor::callee() {
  return *getODSOperands(0).begin();
}

ValueRange AppOpOperandAdaptor::operands() {
  return getODSOperands(1);
}

StringRef AppOp::getOperationName() {
  return "lambdapure.AppOp";
}

std::pair<unsigned, unsigned> AppOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {false, true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 1) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

Operation::operand_range AppOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

Value AppOp::callee() {
  return *getODSOperands(0).begin();
}

Operation::operand_range AppOp::operands() {
  return getODSOperands(1);
}

::mlir::MutableOperandRange AppOp::calleeMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange AppOp::operandsMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> AppOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range AppOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}



void AppOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, Value callee, ValueRange operands) {
  odsState.addOperands(callee);
  odsState.addOperands(operands);
  odsState.addTypes(resultType0);
}

void AppOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, Value callee, ValueRange operands) {
  odsState.addOperands(callee);
  odsState.addOperands(operands);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void AppOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  assert(operands.size() >= 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult AppOp::verify() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((true))) {
        return emitOpError("operand #") << index << " must be any type, but got " << v.getType();
      }
      ++index;
    }
    auto valueGroup1 = getODSOperands(1);
    for (Value v : valueGroup1) {
      (void)v;
      if (!((true))) {
        return emitOpError("operand #") << index << " must be any type, but got " << v.getType();
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type, but got " << v.getType();
      }
      ++index;
    }
  }
  return mlir::success();
}


//===----------------------------------------------------------------------===//
// lambdapure::BoxOp definitions
//===----------------------------------------------------------------------===//

BoxOpOperandAdaptor::BoxOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

BoxOpOperandAdaptor::BoxOpOperandAdaptor(BoxOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> BoxOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

ValueRange BoxOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

IntegerAttr BoxOpOperandAdaptor::value() {
  assert(odsAttrs && "no attributes when constructing adapter");
  IntegerAttr attr = odsAttrs.get("value").cast<IntegerAttr>();
  return attr;
}

StringRef BoxOp::getOperationName() {
  return "lambdapure.BoxOp";
}

std::pair<unsigned, unsigned> BoxOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::operand_range BoxOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

std::pair<unsigned, unsigned> BoxOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range BoxOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

IntegerAttr BoxOp::valueAttr() {
  return this->getAttr("value").cast<IntegerAttr>();
}

APInt BoxOp::value() {
  auto attr = valueAttr();
  return attr.getValue();
}

void BoxOp::valueAttr(IntegerAttr attr) {
  this->getOperation()->setAttr("value", attr);
}

void BoxOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, IntegerAttr value) {
  odsState.addAttribute("value", value);
  odsState.addTypes(resultType0);
}

void BoxOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr value) {
  odsState.addAttribute("value", value);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void BoxOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, APInt value) {
  odsState.addAttribute("value", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), value));
  odsState.addTypes(resultType0);
}

void BoxOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt value) {
  odsState.addAttribute("value", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), value));
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void BoxOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult BoxOp::verify() {
  auto tblgen_value = this->getAttr("value");
  if (!tblgen_value) return emitOpError("requires attribute 'value'");
  {
    if (!(((tblgen_value.isa<IntegerAttr>())) && ((tblgen_value.cast<IntegerAttr>().getType().isSignlessInteger(64))))) return emitOpError("attribute 'value' failed to satisfy constraint: 64-bit signless integer attribute");
  }
  {
    unsigned index = 0; (void)index;
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("result #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  return mlir::success();
}

void BoxOp::getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects) {

}


//===----------------------------------------------------------------------===//
// lambdapure::CallOp definitions
//===----------------------------------------------------------------------===//

CallOpOperandAdaptor::CallOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

CallOpOperandAdaptor::CallOpOperandAdaptor(CallOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> CallOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperands.size() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

ValueRange CallOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

ValueRange CallOpOperandAdaptor::inputs() {
  return getODSOperands(0);
}

FlatSymbolRefAttr CallOpOperandAdaptor::callee() {
  assert(odsAttrs && "no attributes when constructing adapter");
  FlatSymbolRefAttr attr = odsAttrs.get("callee").cast<FlatSymbolRefAttr>();
  return attr;
}

StringRef CallOp::getOperationName() {
  return "lambdapure.CallOp";
}

std::pair<unsigned, unsigned> CallOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

Operation::operand_range CallOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

Operation::operand_range CallOp::inputs() {
  return getODSOperands(0);
}

::mlir::MutableOperandRange CallOp::inputsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> CallOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range CallOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

FlatSymbolRefAttr CallOp::calleeAttr() {
  return this->getAttr("callee").cast<FlatSymbolRefAttr>();
}

StringRef CallOp::callee() {
  auto attr = calleeAttr();
  return attr.getValue();
}

void CallOp::calleeAttr(FlatSymbolRefAttr attr) {
  this->getOperation()->setAttr("callee", attr);
}



void CallOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, FlatSymbolRefAttr callee, ValueRange inputs) {
  odsState.addOperands(inputs);
  odsState.addAttribute("callee", callee);
  odsState.addTypes(resultType0);
}

void CallOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, FlatSymbolRefAttr callee, ValueRange inputs) {
  odsState.addOperands(inputs);
  odsState.addAttribute("callee", callee);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void CallOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, StringRef callee, ValueRange inputs) {
  odsState.addOperands(inputs);
  odsState.addAttribute("callee", odsBuilder.getSymbolRefAttr(callee));
  odsState.addTypes(resultType0);
}

void CallOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, StringRef callee, ValueRange inputs) {
  odsState.addOperands(inputs);
  odsState.addAttribute("callee", odsBuilder.getSymbolRefAttr(callee));
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void CallOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult CallOp::verify() {
  auto tblgen_callee = this->getAttr("callee");
  if (!tblgen_callee) return emitOpError("requires attribute 'callee'");
  {
    if (!((tblgen_callee.isa<FlatSymbolRefAttr>()))) return emitOpError("attribute 'callee' failed to satisfy constraint: flat symbol reference attribute");
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((true))) {
        return emitOpError("operand #") << index << " must be any type, but got " << v.getType();
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((true))) {
        return emitOpError("result #") << index << " must be any type, but got " << v.getType();
      }
      ++index;
    }
  }
  return mlir::success();
}


//===----------------------------------------------------------------------===//
// lambdapure::CaseOp definitions
//===----------------------------------------------------------------------===//

CaseOpOperandAdaptor::CaseOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

CaseOpOperandAdaptor::CaseOpOperandAdaptor(CaseOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> CaseOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

ValueRange CaseOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

Value CaseOpOperandAdaptor::operand() {
  return *getODSOperands(0).begin();
}

StringRef CaseOp::getOperationName() {
  return "lambdapure.CaseOp";
}

std::pair<unsigned, unsigned> CaseOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::operand_range CaseOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

Value CaseOp::operand() {
  return *getODSOperands(0).begin();
}

::mlir::MutableOperandRange CaseOp::operandMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> CaseOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range CaseOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

MutableArrayRef<Region> CaseOp::region() {
  return this->getOperation()->getRegions().drop_front(0);
}

void CaseOp::build(OpBuilder &odsBuilder, OperationState &odsState, Value operand, unsigned regionCount) {
  odsState.addOperands(operand);
  for (unsigned i = 0; i < regionCount; ++i)
    (void)odsState.addRegion();
}

void CaseOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, Value operand, unsigned regionCount) {
  odsState.addOperands(operand);
  for (unsigned i = 0; i < regionCount; ++i)
    (void)odsState.addRegion();
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void CaseOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes, unsigned numRegions) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  for (unsigned i = 0; i != numRegions; ++i)
    (void)odsState.addRegion();
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult CaseOp::verify() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isSignlessInteger(8)))) {
        return emitOpError("operand #") << index << " must be 8-bit signless integer, but got " << v.getType();
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
  }
{
    unsigned index = 0; (void)index;
    for (Region &region : region()) {
      (void)region;
      if (!((true))) {
        return emitOpError("region #") << index << " ('region') failed to verify constraint: any region";
      }
      ++index;
    }
  }
  return mlir::success();
}

void CaseOp::getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects) {

}


//===----------------------------------------------------------------------===//
// lambdapure::ConstructorOp definitions
//===----------------------------------------------------------------------===//

ConstructorOpOperandAdaptor::ConstructorOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

ConstructorOpOperandAdaptor::ConstructorOpOperandAdaptor(ConstructorOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> ConstructorOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperands.size() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

ValueRange ConstructorOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

ValueRange ConstructorOpOperandAdaptor::operands() {
  return getODSOperands(0);
}

IntegerAttr ConstructorOpOperandAdaptor::tag() {
  assert(odsAttrs && "no attributes when constructing adapter");
  IntegerAttr attr = odsAttrs.get("tag").cast<IntegerAttr>();
  return attr;
}

StringRef ConstructorOp::getOperationName() {
  return "lambdapure.ConstructorOp";
}

std::pair<unsigned, unsigned> ConstructorOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

Operation::operand_range ConstructorOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

Operation::operand_range ConstructorOp::operands() {
  return getODSOperands(0);
}

::mlir::MutableOperandRange ConstructorOp::operandsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> ConstructorOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range ConstructorOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

IntegerAttr ConstructorOp::tagAttr() {
  return this->getAttr("tag").cast<IntegerAttr>();
}

APInt ConstructorOp::tag() {
  auto attr = tagAttr();
  return attr.getValue();
}

void ConstructorOp::tagAttr(IntegerAttr attr) {
  this->getOperation()->setAttr("tag", attr);
}



void ConstructorOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, IntegerAttr tag, ValueRange operands) {
  odsState.addOperands(operands);
  odsState.addAttribute("tag", tag);
  odsState.addTypes(resultType0);
}

void ConstructorOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr tag, ValueRange operands) {
  odsState.addOperands(operands);
  odsState.addAttribute("tag", tag);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ConstructorOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, APInt tag, ValueRange operands) {
  odsState.addOperands(operands);
  odsState.addAttribute("tag", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), tag));
  odsState.addTypes(resultType0);
}

void ConstructorOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt tag, ValueRange operands) {
  odsState.addOperands(operands);
  odsState.addAttribute("tag", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), tag));
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ConstructorOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult ConstructorOp::verify() {
  auto tblgen_tag = this->getAttr("tag");
  if (!tblgen_tag) return emitOpError("requires attribute 'tag'");
  {
    if (!(((tblgen_tag.isa<IntegerAttr>())) && ((tblgen_tag.cast<IntegerAttr>().getType().isSignlessInteger(64))))) return emitOpError("attribute 'tag' failed to satisfy constraint: 64-bit signless integer attribute");
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("operand #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("result #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  return mlir::success();
}


//===----------------------------------------------------------------------===//
// lambdapure::CtorSetOp definitions
//===----------------------------------------------------------------------===//

CtorSetOpOperandAdaptor::CtorSetOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

CtorSetOpOperandAdaptor::CtorSetOpOperandAdaptor(CtorSetOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> CtorSetOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

ValueRange CtorSetOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

Value CtorSetOpOperandAdaptor::ctor_obj() {
  return *getODSOperands(0).begin();
}

Value CtorSetOpOperandAdaptor::set_obj() {
  return *getODSOperands(1).begin();
}

IntegerAttr CtorSetOpOperandAdaptor::index() {
  assert(odsAttrs && "no attributes when constructing adapter");
  IntegerAttr attr = odsAttrs.get("index").cast<IntegerAttr>();
  return attr;
}

StringRef CtorSetOp::getOperationName() {
  return "lambdapure.CtorSetOp";
}

std::pair<unsigned, unsigned> CtorSetOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::operand_range CtorSetOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

Value CtorSetOp::ctor_obj() {
  return *getODSOperands(0).begin();
}

Value CtorSetOp::set_obj() {
  return *getODSOperands(1).begin();
}

::mlir::MutableOperandRange CtorSetOp::ctor_objMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange CtorSetOp::set_objMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> CtorSetOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range CtorSetOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

IntegerAttr CtorSetOp::indexAttr() {
  return this->getAttr("index").cast<IntegerAttr>();
}

APInt CtorSetOp::index() {
  auto attr = indexAttr();
  return attr.getValue();
}

void CtorSetOp::indexAttr(IntegerAttr attr) {
  this->getOperation()->setAttr("index", attr);
}

void CtorSetOp::build(OpBuilder &odsBuilder, OperationState &odsState, IntegerAttr index, Value ctor_obj, Value set_obj) {
  odsState.addOperands(ctor_obj);
  odsState.addOperands(set_obj);
  odsState.addAttribute("index", index);
}

void CtorSetOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr index, Value ctor_obj, Value set_obj) {
  odsState.addOperands(ctor_obj);
  odsState.addOperands(set_obj);
  odsState.addAttribute("index", index);
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void CtorSetOp::build(OpBuilder &odsBuilder, OperationState &odsState, APInt index, Value ctor_obj, Value set_obj) {
  odsState.addOperands(ctor_obj);
  odsState.addOperands(set_obj);
  odsState.addAttribute("index", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), index));
}

void CtorSetOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt index, Value ctor_obj, Value set_obj) {
  odsState.addOperands(ctor_obj);
  odsState.addOperands(set_obj);
  odsState.addAttribute("index", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), index));
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void CtorSetOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult CtorSetOp::verify() {
  auto tblgen_index = this->getAttr("index");
  if (!tblgen_index) return emitOpError("requires attribute 'index'");
  {
    if (!(((tblgen_index.isa<IntegerAttr>())) && ((tblgen_index.cast<IntegerAttr>().getType().isSignlessInteger(64))))) return emitOpError("attribute 'index' failed to satisfy constraint: 64-bit signless integer attribute");
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("operand #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
    auto valueGroup1 = getODSOperands(1);
    for (Value v : valueGroup1) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("operand #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
  }
  return mlir::success();
}


//===----------------------------------------------------------------------===//
// lambdapure::DecOp definitions
//===----------------------------------------------------------------------===//

DecOpOperandAdaptor::DecOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

DecOpOperandAdaptor::DecOpOperandAdaptor(DecOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> DecOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

ValueRange DecOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

Value DecOpOperandAdaptor::object() {
  return *getODSOperands(0).begin();
}

StringRef DecOp::getOperationName() {
  return "lambdapure.DecOp";
}

std::pair<unsigned, unsigned> DecOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::operand_range DecOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

Value DecOp::object() {
  return *getODSOperands(0).begin();
}

::mlir::MutableOperandRange DecOp::objectMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> DecOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range DecOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

void DecOp::build(OpBuilder &odsBuilder, OperationState &odsState, Value object) {
  odsState.addOperands(object);
}

void DecOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, Value object) {
  odsState.addOperands(object);
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void DecOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult DecOp::verify() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("operand #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
  }
  return mlir::success();
}


//===----------------------------------------------------------------------===//
// lambdapure::IncOp definitions
//===----------------------------------------------------------------------===//

IncOpOperandAdaptor::IncOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

IncOpOperandAdaptor::IncOpOperandAdaptor(IncOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> IncOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

ValueRange IncOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

Value IncOpOperandAdaptor::object() {
  return *getODSOperands(0).begin();
}

StringRef IncOp::getOperationName() {
  return "lambdapure.IncOp";
}

std::pair<unsigned, unsigned> IncOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::operand_range IncOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

Value IncOp::object() {
  return *getODSOperands(0).begin();
}

::mlir::MutableOperandRange IncOp::objectMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> IncOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range IncOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

void IncOp::build(OpBuilder &odsBuilder, OperationState &odsState, Value object) {
  odsState.addOperands(object);
}

void IncOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, Value object) {
  odsState.addOperands(object);
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void IncOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult IncOp::verify() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("operand #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
  }
  return mlir::success();
}


//===----------------------------------------------------------------------===//
// lambdapure::IntegerConstOp definitions
//===----------------------------------------------------------------------===//

IntegerConstOpOperandAdaptor::IntegerConstOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

IntegerConstOpOperandAdaptor::IntegerConstOpOperandAdaptor(IntegerConstOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> IntegerConstOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

ValueRange IntegerConstOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

IntegerAttr IntegerConstOpOperandAdaptor::value() {
  assert(odsAttrs && "no attributes when constructing adapter");
  IntegerAttr attr = odsAttrs.get("value").cast<IntegerAttr>();
  return attr;
}

StringRef IntegerConstOp::getOperationName() {
  return "lambdapure.IntegerConst";
}

std::pair<unsigned, unsigned> IntegerConstOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::operand_range IntegerConstOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

std::pair<unsigned, unsigned> IntegerConstOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range IntegerConstOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

IntegerAttr IntegerConstOp::valueAttr() {
  return this->getAttr("value").cast<IntegerAttr>();
}

APInt IntegerConstOp::value() {
  auto attr = valueAttr();
  return attr.getValue();
}

void IntegerConstOp::valueAttr(IntegerAttr attr) {
  this->getOperation()->setAttr("value", attr);
}



void IntegerConstOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, IntegerAttr value) {
  odsState.addAttribute("value", value);
  odsState.addTypes(resultType0);
}

void IntegerConstOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr value) {
  odsState.addAttribute("value", value);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void IntegerConstOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, APInt value) {
  odsState.addAttribute("value", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), value));
  odsState.addTypes(resultType0);
}

void IntegerConstOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt value) {
  odsState.addAttribute("value", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), value));
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void IntegerConstOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult IntegerConstOp::verify() {
  auto tblgen_value = this->getAttr("value");
  if (!tblgen_value) return emitOpError("requires attribute 'value'");
  {
    if (!(((tblgen_value.isa<IntegerAttr>())) && ((tblgen_value.cast<IntegerAttr>().getType().isSignlessInteger(64))))) return emitOpError("attribute 'value' failed to satisfy constraint: 64-bit signless integer attribute");
  }
  {
    unsigned index = 0; (void)index;
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("result #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  return mlir::success();
}

void IntegerConstOp::getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects) {

}


//===----------------------------------------------------------------------===//
// lambdapure::PapOp definitions
//===----------------------------------------------------------------------===//

PapOpOperandAdaptor::PapOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

PapOpOperandAdaptor::PapOpOperandAdaptor(PapOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> PapOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperands.size() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

ValueRange PapOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

ValueRange PapOpOperandAdaptor::operands() {
  return getODSOperands(0);
}

FlatSymbolRefAttr PapOpOperandAdaptor::callee() {
  assert(odsAttrs && "no attributes when constructing adapter");
  FlatSymbolRefAttr attr = odsAttrs.get("callee").cast<FlatSymbolRefAttr>();
  return attr;
}

StringRef PapOp::getOperationName() {
  return "lambdapure.PapOp";
}

std::pair<unsigned, unsigned> PapOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

Operation::operand_range PapOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

Operation::operand_range PapOp::operands() {
  return getODSOperands(0);
}

::mlir::MutableOperandRange PapOp::operandsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> PapOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range PapOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

FlatSymbolRefAttr PapOp::calleeAttr() {
  return this->getAttr("callee").cast<FlatSymbolRefAttr>();
}

StringRef PapOp::callee() {
  auto attr = calleeAttr();
  return attr.getValue();
}

void PapOp::calleeAttr(FlatSymbolRefAttr attr) {
  this->getOperation()->setAttr("callee", attr);
}



void PapOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, FlatSymbolRefAttr callee, ValueRange operands) {
  odsState.addOperands(operands);
  odsState.addAttribute("callee", callee);
  odsState.addTypes(resultType0);
}

void PapOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, FlatSymbolRefAttr callee, ValueRange operands) {
  odsState.addOperands(operands);
  odsState.addAttribute("callee", callee);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void PapOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, StringRef callee, ValueRange operands) {
  odsState.addOperands(operands);
  odsState.addAttribute("callee", odsBuilder.getSymbolRefAttr(callee));
  odsState.addTypes(resultType0);
}

void PapOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, StringRef callee, ValueRange operands) {
  odsState.addOperands(operands);
  odsState.addAttribute("callee", odsBuilder.getSymbolRefAttr(callee));
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void PapOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult PapOp::verify() {
  auto tblgen_callee = this->getAttr("callee");
  if (!tblgen_callee) return emitOpError("requires attribute 'callee'");
  {
    if (!((tblgen_callee.isa<FlatSymbolRefAttr>()))) return emitOpError("attribute 'callee' failed to satisfy constraint: flat symbol reference attribute");
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("operand #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("result #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  return mlir::success();
}


//===----------------------------------------------------------------------===//
// lambdapure::ProjectionOp definitions
//===----------------------------------------------------------------------===//

ProjectionOpOperandAdaptor::ProjectionOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

ProjectionOpOperandAdaptor::ProjectionOpOperandAdaptor(ProjectionOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> ProjectionOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

ValueRange ProjectionOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

Value ProjectionOpOperandAdaptor::operand() {
  return *getODSOperands(0).begin();
}

IntegerAttr ProjectionOpOperandAdaptor::index() {
  assert(odsAttrs && "no attributes when constructing adapter");
  IntegerAttr attr = odsAttrs.get("index").cast<IntegerAttr>();
  return attr;
}

StringRef ProjectionOp::getOperationName() {
  return "lambdapure.ProjectionOp";
}

std::pair<unsigned, unsigned> ProjectionOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::operand_range ProjectionOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

Value ProjectionOp::operand() {
  return *getODSOperands(0).begin();
}

::mlir::MutableOperandRange ProjectionOp::operandMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> ProjectionOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range ProjectionOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

IntegerAttr ProjectionOp::indexAttr() {
  return this->getAttr("index").cast<IntegerAttr>();
}

APInt ProjectionOp::index() {
  auto attr = indexAttr();
  return attr.getValue();
}

void ProjectionOp::indexAttr(IntegerAttr attr) {
  this->getOperation()->setAttr("index", attr);
}



void ProjectionOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, IntegerAttr index, Value operand) {
  odsState.addOperands(operand);
  odsState.addAttribute("index", index);
  odsState.addTypes(resultType0);
}

void ProjectionOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr index, Value operand) {
  odsState.addOperands(operand);
  odsState.addAttribute("index", index);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ProjectionOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, APInt index, Value operand) {
  odsState.addOperands(operand);
  odsState.addAttribute("index", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), index));
  odsState.addTypes(resultType0);
}

void ProjectionOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt index, Value operand) {
  odsState.addOperands(operand);
  odsState.addAttribute("index", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), index));
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ProjectionOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult ProjectionOp::verify() {
  auto tblgen_index = this->getAttr("index");
  if (!tblgen_index) return emitOpError("requires attribute 'index'");
  {
    if (!(((tblgen_index.isa<IntegerAttr>())) && ((tblgen_index.cast<IntegerAttr>().getType().isSignlessInteger(64))))) return emitOpError("attribute 'index' failed to satisfy constraint: 64-bit signless integer attribute");
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("operand #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("result #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  return mlir::success();
}

void ProjectionOp::getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects) {

}


//===----------------------------------------------------------------------===//
// lambdapure::ResetOp definitions
//===----------------------------------------------------------------------===//

ResetOpOperandAdaptor::ResetOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

ResetOpOperandAdaptor::ResetOpOperandAdaptor(ResetOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> ResetOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

ValueRange ResetOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

Value ResetOpOperandAdaptor::object() {
  return *getODSOperands(0).begin();
}

StringRef ResetOp::getOperationName() {
  return "lambdapure.ResetOp";
}

std::pair<unsigned, unsigned> ResetOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::operand_range ResetOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

Value ResetOp::object() {
  return *getODSOperands(0).begin();
}

::mlir::MutableOperandRange ResetOp::objectMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> ResetOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range ResetOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

MutableArrayRef<Region> ResetOp::region() {
  return this->getOperation()->getRegions().drop_front(0);
}

void ResetOp::build(OpBuilder &odsBuilder, OperationState &odsState, Value object, unsigned regionCount) {
  odsState.addOperands(object);
  for (unsigned i = 0; i < regionCount; ++i)
    (void)odsState.addRegion();
}

void ResetOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, Value object, unsigned regionCount) {
  odsState.addOperands(object);
  for (unsigned i = 0; i < regionCount; ++i)
    (void)odsState.addRegion();
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ResetOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes, unsigned numRegions) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  for (unsigned i = 0; i != numRegions; ++i)
    (void)odsState.addRegion();
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult ResetOp::verify() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("operand #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
  }
{
    unsigned index = 0; (void)index;
    for (Region &region : region()) {
      (void)region;
      if (!((true))) {
        return emitOpError("region #") << index << " ('region') failed to verify constraint: any region";
      }
      ++index;
    }
  }
  return mlir::success();
}

void ResetOp::getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects) {

}


//===----------------------------------------------------------------------===//
// lambdapure::ReturnOp definitions
//===----------------------------------------------------------------------===//

ReturnOpOperandAdaptor::ReturnOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

ReturnOpOperandAdaptor::ReturnOpOperandAdaptor(ReturnOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> ReturnOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

ValueRange ReturnOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

Value ReturnOpOperandAdaptor::input() {
  return *getODSOperands(0).begin();
}

StringRef ReturnOp::getOperationName() {
  return "lambdapure.ReturnOp";
}

std::pair<unsigned, unsigned> ReturnOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::operand_range ReturnOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

Value ReturnOp::input() {
  return *getODSOperands(0).begin();
}

::mlir::MutableOperandRange ReturnOp::inputMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> ReturnOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range ReturnOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

void ReturnOp::build(OpBuilder &odsBuilder, OperationState &odsState, Value input) {
  odsState.addOperands(input);
}

void ReturnOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, Value input) {
  odsState.addOperands(input);
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ReturnOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult ReturnOp::verify() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((true))) {
        return emitOpError("operand #") << index << " must be any type, but got " << v.getType();
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
  }
  return mlir::success();
}

void ReturnOp::getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects) {

}


//===----------------------------------------------------------------------===//
// lambdapure::ReuseAllocCtorOp definitions
//===----------------------------------------------------------------------===//

ReuseAllocCtorOpOperandAdaptor::ReuseAllocCtorOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

ReuseAllocCtorOpOperandAdaptor::ReuseAllocCtorOpOperandAdaptor(ReuseAllocCtorOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> ReuseAllocCtorOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

ValueRange ReuseAllocCtorOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

Value ReuseAllocCtorOpOperandAdaptor::object() {
  return *getODSOperands(0).begin();
}

IntegerAttr ReuseAllocCtorOpOperandAdaptor::tag() {
  assert(odsAttrs && "no attributes when constructing adapter");
  IntegerAttr attr = odsAttrs.get("tag").cast<IntegerAttr>();
  return attr;
}

IntegerAttr ReuseAllocCtorOpOperandAdaptor::size() {
  assert(odsAttrs && "no attributes when constructing adapter");
  IntegerAttr attr = odsAttrs.get("size").cast<IntegerAttr>();
  return attr;
}

StringRef ReuseAllocCtorOp::getOperationName() {
  return "lambdapure.ReuseAllocCtorOp";
}

std::pair<unsigned, unsigned> ReuseAllocCtorOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::operand_range ReuseAllocCtorOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

Value ReuseAllocCtorOp::object() {
  return *getODSOperands(0).begin();
}

::mlir::MutableOperandRange ReuseAllocCtorOp::objectMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> ReuseAllocCtorOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range ReuseAllocCtorOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

IntegerAttr ReuseAllocCtorOp::tagAttr() {
  return this->getAttr("tag").cast<IntegerAttr>();
}

APInt ReuseAllocCtorOp::tag() {
  auto attr = tagAttr();
  return attr.getValue();
}

IntegerAttr ReuseAllocCtorOp::sizeAttr() {
  return this->getAttr("size").cast<IntegerAttr>();
}

APInt ReuseAllocCtorOp::size() {
  auto attr = sizeAttr();
  return attr.getValue();
}

void ReuseAllocCtorOp::tagAttr(IntegerAttr attr) {
  this->getOperation()->setAttr("tag", attr);
}

void ReuseAllocCtorOp::sizeAttr(IntegerAttr attr) {
  this->getOperation()->setAttr("size", attr);
}

void ReuseAllocCtorOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, IntegerAttr tag, IntegerAttr size, Value object) {
  odsState.addOperands(object);
  odsState.addAttribute("tag", tag);
  odsState.addAttribute("size", size);
  odsState.addTypes(resultType0);
}

void ReuseAllocCtorOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr tag, IntegerAttr size, Value object) {
  odsState.addOperands(object);
  odsState.addAttribute("tag", tag);
  odsState.addAttribute("size", size);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ReuseAllocCtorOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, APInt tag, APInt size, Value object) {
  odsState.addOperands(object);
  odsState.addAttribute("tag", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), tag));
  odsState.addAttribute("size", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), size));
  odsState.addTypes(resultType0);
}

void ReuseAllocCtorOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt tag, APInt size, Value object) {
  odsState.addOperands(object);
  odsState.addAttribute("tag", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), tag));
  odsState.addAttribute("size", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), size));
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ReuseAllocCtorOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult ReuseAllocCtorOp::verify() {
  auto tblgen_tag = this->getAttr("tag");
  if (!tblgen_tag) return emitOpError("requires attribute 'tag'");
  {
    if (!(((tblgen_tag.isa<IntegerAttr>())) && ((tblgen_tag.cast<IntegerAttr>().getType().isSignlessInteger(64))))) return emitOpError("attribute 'tag' failed to satisfy constraint: 64-bit signless integer attribute");
  }
  auto tblgen_size = this->getAttr("size");
  if (!tblgen_size) return emitOpError("requires attribute 'size'");
  {
    if (!(((tblgen_size.isa<IntegerAttr>())) && ((tblgen_size.cast<IntegerAttr>().getType().isSignlessInteger(64))))) return emitOpError("attribute 'size' failed to satisfy constraint: 64-bit signless integer attribute");
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("operand #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("result #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  return mlir::success();
}


//===----------------------------------------------------------------------===//
// lambdapure::ReuseConstructorOp definitions
//===----------------------------------------------------------------------===//

ReuseConstructorOpOperandAdaptor::ReuseConstructorOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

ReuseConstructorOpOperandAdaptor::ReuseConstructorOpOperandAdaptor(ReuseConstructorOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> ReuseConstructorOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (odsOperands.size() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

ValueRange ReuseConstructorOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

ValueRange ReuseConstructorOpOperandAdaptor::operands() {
  return getODSOperands(0);
}

IntegerAttr ReuseConstructorOpOperandAdaptor::tag() {
  assert(odsAttrs && "no attributes when constructing adapter");
  IntegerAttr attr = odsAttrs.get("tag").cast<IntegerAttr>();
  return attr;
}

StringRef ReuseConstructorOp::getOperationName() {
  return "lambdapure.ReuseConstructorOp";
}

std::pair<unsigned, unsigned> ReuseConstructorOp::getODSOperandIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumOperands() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

Operation::operand_range ReuseConstructorOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

Operation::operand_range ReuseConstructorOp::operands() {
  return getODSOperands(0);
}

::mlir::MutableOperandRange ReuseConstructorOp::operandsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> ReuseConstructorOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range ReuseConstructorOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

IntegerAttr ReuseConstructorOp::tagAttr() {
  return this->getAttr("tag").cast<IntegerAttr>();
}

APInt ReuseConstructorOp::tag() {
  auto attr = tagAttr();
  return attr.getValue();
}

void ReuseConstructorOp::tagAttr(IntegerAttr attr) {
  this->getOperation()->setAttr("tag", attr);
}



void ReuseConstructorOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, IntegerAttr tag, ValueRange operands) {
  odsState.addOperands(operands);
  odsState.addAttribute("tag", tag);
  odsState.addTypes(resultType0);
}

void ReuseConstructorOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr tag, ValueRange operands) {
  odsState.addOperands(operands);
  odsState.addAttribute("tag", tag);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ReuseConstructorOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, APInt tag, ValueRange operands) {
  odsState.addOperands(operands);
  odsState.addAttribute("tag", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), tag));
  odsState.addTypes(resultType0);
}

void ReuseConstructorOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt tag, ValueRange operands) {
  odsState.addOperands(operands);
  odsState.addAttribute("tag", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(64), tag));
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ReuseConstructorOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult ReuseConstructorOp::verify() {
  auto tblgen_tag = this->getAttr("tag");
  if (!tblgen_tag) return emitOpError("requires attribute 'tag'");
  {
    if (!(((tblgen_tag.isa<IntegerAttr>())) && ((tblgen_tag.cast<IntegerAttr>().getType().isSignlessInteger(64))))) return emitOpError("attribute 'tag' failed to satisfy constraint: 64-bit signless integer attribute");
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("operand #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("result #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  return mlir::success();
}


//===----------------------------------------------------------------------===//
// lambdapure::TagGetOp definitions
//===----------------------------------------------------------------------===//

TagGetOpOperandAdaptor::TagGetOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

TagGetOpOperandAdaptor::TagGetOpOperandAdaptor(TagGetOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> TagGetOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

ValueRange TagGetOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

Value TagGetOpOperandAdaptor::object() {
  return *getODSOperands(0).begin();
}

StringRef TagGetOp::getOperationName() {
  return "lambdapure.TagGetOp";
}

std::pair<unsigned, unsigned> TagGetOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::operand_range TagGetOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

Value TagGetOp::object() {
  return *getODSOperands(0).begin();
}

::mlir::MutableOperandRange TagGetOp::objectMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> TagGetOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range TagGetOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

void TagGetOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, Value object) {
  odsState.addOperands(object);
  odsState.addTypes(resultType0);
}

void TagGetOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, Value object) {
  odsState.addOperands(object);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void TagGetOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult TagGetOp::verify() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("operand #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isSignlessInteger(8)))) {
        return emitOpError("result #") << index << " must be 8-bit signless integer, but got " << v.getType();
      }
      ++index;
    }
  }
  return mlir::success();
}

void TagGetOp::getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects) {

}


//===----------------------------------------------------------------------===//
// lambdapure::TagSetOp definitions
//===----------------------------------------------------------------------===//

TagSetOpOperandAdaptor::TagSetOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

TagSetOpOperandAdaptor::TagSetOpOperandAdaptor(TagSetOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> TagSetOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

ValueRange TagSetOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

Value TagSetOpOperandAdaptor::object() {
  return *getODSOperands(0).begin();
}

IntegerAttr TagSetOpOperandAdaptor::tag() {
  assert(odsAttrs && "no attributes when constructing adapter");
  IntegerAttr attr = odsAttrs.get("tag").cast<IntegerAttr>();
  return attr;
}

StringRef TagSetOp::getOperationName() {
  return "lambdapure.TagSetOp";
}

std::pair<unsigned, unsigned> TagSetOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::operand_range TagSetOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

Value TagSetOp::object() {
  return *getODSOperands(0).begin();
}

::mlir::MutableOperandRange TagSetOp::objectMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> TagSetOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range TagSetOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

IntegerAttr TagSetOp::tagAttr() {
  return this->getAttr("tag").cast<IntegerAttr>();
}

APInt TagSetOp::tag() {
  auto attr = tagAttr();
  return attr.getValue();
}

void TagSetOp::tagAttr(IntegerAttr attr) {
  this->getOperation()->setAttr("tag", attr);
}

void TagSetOp::build(OpBuilder &odsBuilder, OperationState &odsState, IntegerAttr tag, Value object) {
  odsState.addOperands(object);
  odsState.addAttribute("tag", tag);
}

void TagSetOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, IntegerAttr tag, Value object) {
  odsState.addOperands(object);
  odsState.addAttribute("tag", tag);
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void TagSetOp::build(OpBuilder &odsBuilder, OperationState &odsState, APInt tag, Value object) {
  odsState.addOperands(object);
  odsState.addAttribute("tag", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(8), tag));
}

void TagSetOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, APInt tag, Value object) {
  odsState.addOperands(object);
  odsState.addAttribute("tag", odsBuilder.getIntegerAttr(odsBuilder.getIntegerType(8), tag));
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void TagSetOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult TagSetOp::verify() {
  auto tblgen_tag = this->getAttr("tag");
  if (!tblgen_tag) return emitOpError("requires attribute 'tag'");
  {
    if (!(((tblgen_tag.isa<IntegerAttr>())) && ((tblgen_tag.cast<IntegerAttr>().getType().isSignlessInteger(8))))) return emitOpError("attribute 'tag' failed to satisfy constraint: 8-bit signless integer attribute");
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("operand #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
  }
  return mlir::success();
}

void TagSetOp::getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects) {

}


//===----------------------------------------------------------------------===//
// lambdapure::UnboxOp definitions
//===----------------------------------------------------------------------===//

UnboxOpOperandAdaptor::UnboxOpOperandAdaptor(ValueRange values, DictionaryAttr attrs )  : odsOperands(values), odsAttrs(attrs) {

}

UnboxOpOperandAdaptor::UnboxOpOperandAdaptor(UnboxOp& op)  : odsOperands(op.getOperation()->getOperands()), odsAttrs(op.getOperation()->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> UnboxOpOperandAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

ValueRange UnboxOpOperandAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

Value UnboxOpOperandAdaptor::object() {
  return *getODSOperands(0).begin();
}

StringRef UnboxOp::getOperationName() {
  return "lambdapure.UnboxOp";
}

std::pair<unsigned, unsigned> UnboxOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::operand_range UnboxOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

Value UnboxOp::object() {
  return *getODSOperands(0).begin();
}

::mlir::MutableOperandRange UnboxOp::objectMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> UnboxOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

Operation::result_range UnboxOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

void UnboxOp::build(OpBuilder &odsBuilder, OperationState &odsState, Type resultType0, Value object) {
  odsState.addOperands(object);
  odsState.addTypes(resultType0);
}

void UnboxOp::build(OpBuilder &odsBuilder, OperationState &odsState, ArrayRef<Type> resultTypes, Value object) {
  odsState.addOperands(object);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void UnboxOp::build(OpBuilder &, OperationState &odsState, ArrayRef<Type> resultTypes, ValueRange operands, ArrayRef<NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

LogicalResult UnboxOp::verify() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isa<ObjectType>()))) {
        return emitOpError("operand #") << index << " must be Lambdapure object type, but got " << v.getType();
      }
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (Value v : valueGroup0) {
      (void)v;
      if (!((v.getType().isSignlessInteger(64)))) {
        return emitOpError("result #") << index << " must be 64-bit signless integer, but got " << v.getType();
      }
      ++index;
    }
  }
  return mlir::success();
}

void UnboxOp::getEffects(SmallVectorImpl<SideEffects::EffectInstance<MemoryEffects::Effect>> &effects) {

}


#endif  // GET_OP_CLASSES

