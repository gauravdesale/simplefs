#include "disk.h"
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


template<const char L, size_t R>

auto Disk::open(L *path, R nblocks) -> void 
{
    FileDescriptor = ::open(path, O_CREAT|O_RDWR, 0600);
    if(FileDescriptor < 0) {
           char what[BUFSIZ];
           snprintf(what, BUFSIZ, "Unable to open %s: ", path, strerrno(errno));
           throw std::runtime_error(what);
   
    }
}
template<int I, char C>
auto Disk::sanity_check(I blocknum, C *data) -> int {
    char what[BUFSIZ];
    if(blocknum < 0) {
          sprintf(what, BUFSIZ, "blocksize is negative");
    }
    if(blocknum > (int)Blocks) {
        sprintf(what, BUFSIZ, "Too many blocks");
        throw std::invalid_argument(what);
    }
    if(data == NULL) {
        sprintf(what, BUFSIZ, "no data available");
        throw std::invalid_arguement(what);
    }
}

/*now make the reading method and write too and in this use sanity check first and then use lseek with the file descriptor and also blocknum times block size to allocate than much space to read as well as the seek set and if its below zero then do sprintf stuff
also then check with read and with its paramaters and its not block size then also do stuff and then increment reads at the end
write is the same thing with write
*/
auto Disk::read(I blocknum, C *data) -> void {
    sanity_check(blocknum, data);
    if(lseek(FileDescriptor, blocknum*BLOCK_SIZE, SEEK_SET) < 0) {
        char what[BUFSIZ];
        sprintf(what, BUFSIZ, "Unable to load since it is negative lmao");
        throw std::runtime_error(what);
    }
    if(::read(FileDescriptor, data, BLOCK_SIZE) != BLOCK_SIZE) {
        char what[BUFSIZ];
        sprintf(what, BUFSIZ, "Unable to get the block");
        throw std::runtime_error(what);
    }
    Reads++;
}

auto Disk::write(I blocknum, C *data) -> void {
    sanity_check(blocknum, data);
    if(lseek(FileDescriptor, blocknum*BLOCK_SIZE, SEEK_SET) < 0) {
        char what[BUFSIZ];
        sprintf(what, BUFSIZ, "Unable to load since it is negative lmao");
        throw std::runtime_error(what);
    }
    if(::write(FileDescriptor, data, BLOCK_SIZE) != BLOCK_SIZE) {
        char what[BUFSIZ];
        sprintf(what, BUFSIZ, "Unable to get the block");
        throw std::runtime_error(what);
    }
    Writes++;
}
