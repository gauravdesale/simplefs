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
