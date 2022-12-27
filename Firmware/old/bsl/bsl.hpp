#ifndef D0108622_7622_47A8_A0DA_B8928A4F8168
#define D0108622_7622_47A8_A0DA_B8928A4F8168

#if 0

// singleton pattern:
// https://gist.github.com/pazdera/1098119
// https://stackoverflow.com/questions/1008019/c-singleton-design-pattern


class BSL
{
    public:
        static BSL& getInstance()
        {
            static BSL    instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
            return instance;
        }

        void init();
    private:
        BSL() {}                    // Constructor? (the {} brackets) are needed here.

        // C++ 03
        // ========
        // Don't forget to declare these two. You want to make sure they
        // are inaccessible(especially from outside), otherwise, you may accidentally get copies of
        // your singleton appearing.
        BSL(BSL const&);              // Don't Implement
        void operator=(BSL const&); // Don't implement

        // C++ 11
        // =======
        // We can use the better technique of deleting the methods
        // we don't want.
    public:
        BSL(BSL const&)               = delete;
        void operator=(BSL const&)  = delete;

        // Note: Scott Meyers mentions in his Effective Modern
        //       C++ book, that deleted functions should generally
        //       be public as it results in better error messages
        //       due to the compilers behavior to check accessibility
        //       before deleted status
};

#endif
#endif /* D0108622_7622_47A8_A0DA_B8928A4F8168 */
