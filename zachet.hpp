#include <functional>

class Defer {
public:
    //non-default-constructable
    Defer() = delete;

    //При конструировании принимает (лямбда) функцию (просто функцию)
    explicit Defer(std::function<void()> func) 
        : func_(std::move(func)) {}

    //non-copyable
    Defer(const Defer&) = delete;
    Defer& operator=(const Defer&) = delete;

    //non-movable
    Defer(Defer&&) = delete;
    Defer& operator=(Defer&&) = delete;

    //При разрушении вызывает ее
    ~Defer() {
        if (func_) func_();
    }

private:
    std::function<void()> func_;
};