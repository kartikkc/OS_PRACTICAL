#include <iostream>
#include <vector>

using namespace std;

const int BLOCK_SIZE = 100; // size of each memory block

struct Block {
  int startAddress;
  int size;
  bool allocated;
};

class MemoryAllocator {
 private:
  vector<Block> blocks;
  int freeMemory;

 public:
  MemoryAllocator() {
    freeMemory = BLOCK_SIZE;
    blocks.push_back({0, BLOCK_SIZE, false});
  }

  int allocate(int size) {
    for (auto& block : blocks) {
      if (!block.allocated && block.size >= size) {
        block.allocated = true;
        block.size = size;
        freeMemory -= size;
        return block.startAddress;
      }
    }
    return -1;
  }

  void deallocate(int startAddress) {
    for (auto& block : blocks) {
      if (block.startAddress == startAddress) {
        block.allocated = false;
        freeMemory += block.size;
        break;
      }
    }
  }

  int getFreeMemory() { return freeMemory; }
};

int main() {
  MemoryAllocator allocator;

  // allocate memory
  int address1 = allocator.allocate(50);
  cout << "Allocated 50 bytes of memory at address: " << address1 << endl;
  int address2 = allocator.allocate(25);
  cout << "Allocated 25 bytes of memory at address: " << address2 << endl;
  int address3 = allocator.allocate(75);
  cout << "Allocated 75 bytes of memory at address: " << address3 << endl;

  // check free memory
  cout << "Free memory: " << allocator.getFreeMemory() << " bytes" << endl;

  // deallocate memory
  allocator.deallocate(address2);
  cout << "Deallocated 25 bytes of memory at address: " << address2 << endl;

  // check free memory
  cout << "Free memory: " << allocator.getFreeMemory() << " bytes" << endl;

  return 0;
}