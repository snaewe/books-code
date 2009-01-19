#include <windows.h>
#include <vector>
#include <iostream>

class BufferCache {
public:
 BufferCache() : m_pCache(NULL) { }
 ~BufferCache() { LocalFree(m_pCache); }

 void *GetBuffer(SIZE_T cb);
 void ReturnBuffer(void *p);

private:
 void *m_pCache;
};

void *BufferCache::GetBuffer(SIZE_T cb)
{
 // Satisfy from cache if possible
 if (m_pCache && LocalSize(m_pCache) >= cb) {
  void *p = m_pCache;
  m_pCache = NULL;
  return p;
 }
 return LocalAlloc(LMEM_FIXED, cb);
}

// Flawed design - see discussion
void BufferCache::ReturnBuffer(void *p)
{
 SIZE_T cb = LocalSize(p);
 if (cb > LocalSize(m_pCache)) {
  // Returned buffer is bigger than the cache:
  // Keep the returned buffer
  LocalFree(m_pCache);
  m_pCache = p;
 } else {
  // Returned buffer is smaller than the cache:
  // Keep the cache
  LocalFree(p);
 }
}

// Since this is just a quick test, we're going to be sloppy
using namespace std; //  sloppy
int __cdecl main(int argc, char **argv)
{
 BufferCache b;

 // seeding the random number generator is not important here
 // in fact, the distribution isn't important either

 vector<void *> v; // keeps track of allocated memory
 for (;;) {
  // randomly allocate and free
  if (v.size() == 0 || (rand() & 1)) { // allocate
   SIZE_T cb = 100;
   while (cb < 1024 * 1024 && (rand() & 1)) {
    cb *= 2; // exponential decay distribution up to 1MB
   }
   void* p = b.GetBuffer(cb);
   if (p) {
    cout << " A" << LocalSize(p) << "/" << cb;
    v.push_back(p); // append to vector
   }
  } else { // free
   int victim = rand() % v.size(); // choose one at random
   cout << " F" << LocalSize(v[victim]);
   b.ReturnBuffer(v[victim]); // free it
   v[victim] = v.back(); // remove it from the vector
   v.pop_back();
  }
 }
}

