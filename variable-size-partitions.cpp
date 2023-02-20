// #include <iostream>
// #include <vector>

// const int MEMORY_SIZE = 1000; // total size of memory

// struct Block {
//   int startAddress;
//   int size;
//   bool allocated;
// };

// class MemoryAllocator {
//  private:
//   std::vector<Block> blocks;

//  public:
//   MemoryAllocator() {
//     blocks.push_back({0, MEMORY_SIZE, false});
//   }

//   int allocate(int size) {
//     for (auto& block : blocks) {
//       if (!block.allocated && block.size >= size) {
//         // split block into two blocks, one for the requested memory and one for the remainder
//         int startAddress = block.startAddress;
//         block.startAddress += size;
//         block.size -= size;

//         // mark the requested block as allocated
//         blocks.insert(blocks.begin() + (&block - &blocks[0]) + 1, {startAddress, size, true});
//         return startAddress;
//       }
//     }
//     return -1;
//   }

//   void deallocate(int startAddress) {
//     for (auto& block : blocks) {
//       if (block.startAddress == startAddress) {
//         block.allocated = false;

//         // merge block with previous and next blocks if they are not allocated
//         auto prev = &block - 1;
//         auto next = &block + 1;
//         if (prev >= &blocks[0] && !prev->allocated) {
//           block.startAddress = prev->startAddress;
//           block.size += prev->size;
//           blocks.erase(blocks.begin() + (prev - &blocks[0]));
//         }
//         if (next < &blocks[blocks.size()] && !next->allocated) {
//           block.size += next->size;
//           blocks.erase(blocks.begin() + (next - &blocks[0]));
//         }
//         break;
//       }
//     }
//   }

//   int getFreeMemory() {
//     int freeMemory = 0;
//     for (const auto& block : blocks) {
//       if (!block.allocated) {
//         freeMemory += block.size;
//       }
//     }
//     return freeMemory;
//   }
// };

// int main() {
//   MemoryAllocator allocator;

//   // allocate memory
//   int address1 = allocator.allocate(50);
//   std::cout << "Allocated 50 bytes of memory at address: " << address1 << std::endl;
//   int address2 = allocator.allocate(25);
//   std::cout << "Allocated 25 bytes of memory at address: " << address2 << std::endl;
//   int address3 = allocator.allocate(75);
//   std::cout << "Allocated 75 bytes of memory at address: " << address3 << std::endl;

//   // check free memory
//   std::cout << "Free memory: " << allocator.getFreeMemory() << " bytes" << std::endl;

//   // deallocate memory
//   allocator.deallocate(address2);
//   std::cout << "Deallocated 25 bytes of memory at address: " <<
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int ram, n;
    cout << "enter ram size : \n";
    cin >> ram;
    cout << "enter the number of process : \n";
    cin >> n;
    int processes[n];
    cout << "enter the size of each process\n";
    for (int i = 0; i < n; i++)
    {
        cin >> processes[i];
    }
    cout << "Given ram size : " << ram << endl;

    vector<int> allocate(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (ram <= 0)
        {
            break;
        }
        if (ram < processes[i])
        {
            continue;
        }
        allocate[i] = 1;
        // cout << "Process no.\tProcess size\tBlock size" << endl;
        // out << "P" << i + 1 << "\t" <<processes[i]<< "\t" <<processes[i]<< endl;
        ram = ram - processes[i];
    }
    cout << "Process no.\tProcess size\tBlock size" << endl;
    for (int i = 0; i < n; i++)
    {
        if (allocate[i] == 1)
        {
            cout << "P" << i + 1 << "\t\t" << processes[i] << "\t\t" << processes[i] << "\n";
        }

        else if (allocate[i] == -1)
        {
            cout << "P" << i + 1 << "\t\t" << processes[i] << "\t\tNot allocated\n";
        }
    }

    cout << "Rest size of ram: " << ram << endl;
    return 0;
}