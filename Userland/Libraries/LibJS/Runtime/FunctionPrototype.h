/*
 * Copyright (c) 2020-2022, Linus Groh <linusg@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Runtime/Object.h>

namespace JS {

class FunctionPrototype final : public FunctionObject {
    JS_OBJECT(FunctionPrototype, FunctionObject);

public:
    explicit FunctionPrototype(GlobalObject&);
    virtual void initialize(GlobalObject&) override;
    virtual ~FunctionPrototype() override = default;

    virtual ThrowCompletionOr<Value> internal_call(Value this_argument, MarkedVector<Value> arguments_list) override;
    virtual FlyString const& name() const override { return m_name; }

private:
    JS_DECLARE_NATIVE_FUNCTION(apply);
    JS_DECLARE_NATIVE_FUNCTION(bind);
    JS_DECLARE_NATIVE_FUNCTION(call);
    JS_DECLARE_NATIVE_FUNCTION(to_string);
    JS_DECLARE_NATIVE_FUNCTION(symbol_has_instance);

    // Totally unnecessary, but sadly still necessary.
    // TODO: Get rid of the pointless name() method.
    FlyString m_name { "FunctionPrototype" };
};

}
