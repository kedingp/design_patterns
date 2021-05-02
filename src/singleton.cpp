#include "design_patterns/singleton.h"

namespace design_patterns {
MySingleton &MySingleton::getInstance() {
    static MySingleton mySingleton;
    return mySingleton;
}

MySingleton::MySingleton() {}
}