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

