#include <emscripten.h>
#include <emscripten/bind.h>
#include <string>
#include <random>

class TestBed
{
private:
    std::string s_ = "";
public:
    TestBed(const std::string& s) : s_(s)
    {
    }

    std::string test_out() const
    {
        return "Hello from wasm: " + s_;
    }
};

double random_num()
{
    return (rand() % 100) / 2.0;
}

EMSCRIPTEN_BINDINGS(my_module)
{
    emscripten::class_<TestBed>("TestBed").constructor<const std::string&>().function("test_out", &TestBed::test_out);
    emscripten::function("rng", &random_num);
}