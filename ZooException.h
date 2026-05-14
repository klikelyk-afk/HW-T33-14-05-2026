#pragma once
#include <string>

class ZooException {
public:
    virtual std::string showMessage() const = 0;
    virtual ~ZooException() {}
};

class PredatorException : public ZooException {
public:
    std::string showMessage() const override {
        return "Error: Cannot add a predator to a cage with non-predators!";
    }
};

class MaxCapacityException : public ZooException {
public:
    std::string showMessage() const override {
        return "Error: Cage is full! Maximum capacity reached.";
    }
};

class NameException : public ZooException {
public:
    std::string showMessage() const override {
        return "Error: Cannot create animal - name is empty!";
    }
};