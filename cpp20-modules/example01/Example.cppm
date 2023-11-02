// Example.cppm
export module Example;

#define RANDVAL 3

namespace NsExample
{
   int internal_func() {
        return 3;
      }

   export int myrand() {
      return internal_func();
   }
}
