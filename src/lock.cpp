#include <pthread.h>
#include "lock.h"

Lock::Lock(Mutex &m) : m(m) {
  m.lock();
}

Lock::~Lock() {
  m.unlock();
}
