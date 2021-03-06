#include "fs.h"
#include <algorithm>
#include <assert.h>
#include <stdio.h>
#include <string.h>

/*initialize all the stuff with either return or true and also create block and disk objects*/
void FileSystem::debug(Disk *disk) {
    Blocks block;
    disk -> read(0, block.Data);
    printf("Super block \n");
    printf(block.Super.Blocks);
    printf(block.Super.InodeBlocks);
    printf(block.Super.Inodes);
}

bool FileSystem::format(Disk *disk) {
    //write super block
    //clear all other blocks
    SuperBlock super;
    super.MagicNumber = this.MAGIC_NUMBER;
    super.Blocks = this.POINTERS_PER_BLOCK;
    super.InodeBlocks = this.POINTERS_PER_INODE;
    super.Inodes = this.INODES_PER_BLOCK;
    remove(POINTERS_PER_BLOCK);
    return true;
}
bool FileSystem::mount(Disk *disk) {
    disk->read(super.Blocks, super.MagicNumber);
    for(int i = 0; i < super.Blocks; i++) {
        disk->mount();
    }
  BitMap newBit = new BitMap();
  newBit.FreeMemory();  

}
class BitMap {
    public:
        BitMap::BitMap() {
            _Data = 0;
            _Width = 0;
            _Height = 0;
        }
        Bitmap::FreeMemory() {
            if(_Data) {
                detele[] data;
            }
            _Data = NULL:
            _Width = NULL;
            _Height = NULL;
        }
};

ssize_t create() {
    //locate free inode in inode table
    //record free node 
    Block blocks;
    ssize_t returnVal;
    for(ssize_t i = 0; i < POINTERS_PER_BLOCK; i++) {
         if(blocks.Inodes[i] == NULL) {
            returnVal = i;
            break;
         }
    }
   return returnVal;
}

ssize_t FileSystem::stat(size_t inumber) {
    //load inone information 
    uint32_t loadInfo = (uint32_t) inumber;
    Inode newNode;
    newNode.Valid = loadInfo;
    newNode.Size = loadInfo;
    newNode.Indirect = loadInfo;
    return 0;
}

ssize_t write(size_t inumber, char *data, size_t length, size_t offset) {
    //load inode 
    //write block and copy data
    Inode newNode;
    newNode.size = inumber;
    newNode.length = length;
    newNode.indirect = length + offset;
    newNode.Direct = data;
    return 0;
}
