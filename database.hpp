namespace TickTAQ {
    struct Database {
        template<typename T>
            struct Index {
                Index(const Database& db, const char* name);
                virtual ~Index();
            };

        struct Value {
            Value();
            virtual ~Value();
        };

        struct Record {
            Record();
            virtual ~Record();

            template<typename T>
                const T operator[](const Index<T> i);
            const Value& operator[](const char* colName);
        };

        struct Filter {
            Filter(const char* exprOrFile = 0);
            virtual ~Filter();
        };

        struct Cursor {
            Cursor(const Database& db, const Filter& f, const char* param = 0);
            virtual ~Cursor();

            bool hasData();
            Record& getNext();
        };

        Database(const char* dir, unsigned date);
        virtual ~Database();
        const Cursor& getCursor(Filter* f = 0, const char* param = 0);
    };
};

