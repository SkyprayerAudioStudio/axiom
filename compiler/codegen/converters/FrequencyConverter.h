#pragma once

#include "../Converter.h"

namespace MaximCodegen {

    class FrequencyConverter : public Converter {
    public:
        explicit FrequencyConverter(MaximContext *ctx, llvm::Module *module);

        static std::unique_ptr<FrequencyConverter> create(MaximContext *ctx, llvm::Module *module);

    private:
        llvm::Value *fromControl(ComposableModuleClassMethod *method, llvm::Value *val);

        llvm::Value *fromSeconds(ComposableModuleClassMethod *method, llvm::Value *val);

        llvm::Value *fromNote(ComposableModuleClassMethod *method, llvm::Value *val);
    };

}