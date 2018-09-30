class Disk {
    template <int I, char C>
    private:
        struct X { size_t t; int i;};
        const X* x = new X();
        decltype(x->i) FileDescriptor;
        decltype(x->t) Blocks;
        decltype(x->t) Reads;
        decltype(x->t) Writes;
        decltype(x->t) Mounts;
        auto sanity_check(I blocknum, C *data) -> void;
    public:
        template <const char L, size_t R>
        const static size_t BLOCK_SIZE = 4096;
        Disk() : FileDescriptor(0), Blocks(0), Reads(0), Writes(0), Mounts(0) {}
        ~Disk();
        auto open(L *path, R nblocks) -> void;
        auto size() const -> decltype(Blocks) {return Blocks;}
        auto mounted() const -> decltype(Mounts>0) {return Mounts>0;}
        auto mount() -> decltype(Mounts) {Mounts++}
        auto unmount() -> void {if(Mounts>0) Mounts--;}
        auto read(I blocknum, C *data) -> void;
        auto write(I blocknum, C *data) -> void;
};
