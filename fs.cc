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
    SupperBlock super;
    super.MagicNumber = this.MAGIC_NUMBER;
    super.Blocks = this.POINTERS_PER_BLOCK;
    super.InodeBlocks = this.POINTERS_PER_INODE;
    super.Inodes = this.INODES_PER_BLOCK;
    remove(POINTERS_PER_BLOCK);
    return true;
}

