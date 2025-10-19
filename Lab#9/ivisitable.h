#pragma once

class IVisitor;

class IVisitable {
public:
    virtual ~IVisitable() = default;
    virtual void accept(IVisitor& visitor) = 0;
};