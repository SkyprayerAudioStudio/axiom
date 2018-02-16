#pragma once

#include <memory>

#include "Value.h"
#include "Builder.h"
#include "../common/OperatorType.h"

namespace MaximCodegen {

    class MaximContext;

    class Node;

    class Operator {
    public:
        Operator(MaximContext *context, MaximCommon::OperatorType type, Type *leftType, Type *rightType);

        virtual std::unique_ptr<Value> call(Node *node, std::unique_ptr<Value> left, std::unique_ptr<Value> right, SourcePos startPos, SourcePos endPos) = 0;

        MaximCommon::OperatorType type() const { return _type; }

        Type *leftType() const { return _leftType; }

        Type *rightType() const { return _rightType; }

    protected:
        MaximContext *context() const { return _context; }

    private:
        MaximContext *_context;
        MaximCommon::OperatorType _type;
        Type *_leftType;
        Type *_rightType;
    };

}