#ifndef TRITON_CONVERSION_TRITONGPU_TO_LLVM_TYPECONVERTER_H
#define TRITON_CONVERSION_TRITONGPU_TO_LLVM_TYPECONVERTER_H

#include "mlir/Conversion/LLVMCommon/TypeConverter.h"
#include "mlir/Dialect/LLVMIR/LLVMDialect.h"
#include "triton/Conversion/MLIRTypes.h"

using namespace mlir;
using namespace mlir::triton;

class TritonGPUToLLVMTypeConverter : public LLVMTypeConverter {
public:
  using TypeConverter::convertType;

  TritonGPUToLLVMTypeConverter(MLIRContext *ctx, LowerToLLVMOptions &option,
                               const DataLayoutAnalysis *analysis = nullptr);

  Type convertTritonPointerType(triton::PointerType type);

  Value packLLElements(Location loc, ValueRange resultVals,
                       ConversionPatternRewriter &rewriter, Type type,
                       bool packVector = false);

  SmallVector<Value> unpackLLElements(Location loc, Value llvmStruct,
                                      ConversionPatternRewriter &rewriter,
                                      Type type, bool unpackVector = false);

  llvm::Optional<Type> convertTritonTensorType(RankedTensorType type);
};

#endif
