# Infix2Postfix

## Details

The folder contains the implementation of Infix2Postfix algorithm. Implementations are written in a way that, it's easy to understand.

## Following is the List of Implementations

* [C++ with Stack](c++/Infix2Postfix.h)

## Helper Functions

Most implementations contains Helper functions. Function are added to understand what is happening at each step. These function are not requried to run the program and can be delete. 

## Example:
```
#include <iostream>
#include "Infix2Postfix.h"

int main() {
  Infix2Postfix ob("A+B*C");
  ob.Debug(true); // Will output the stack at each step. Only include for testing.
  cout << ob.Convert();
  return 0;
}
```

## Authors

* **g31s** - *Initial work* - [g31s](https://github.com/g31s)

See also the list of [contributors](https://github.com/g31s/algorithms/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for detailsgit 