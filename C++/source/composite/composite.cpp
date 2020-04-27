#include <iostream>
#include <vector>

std::string generateString(size_t len)
{
    std::string str = "";
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (size_t i = 0; i < len; ++i) str += alphabet[rand() % 26];
    return str;
}

// Component
class FileSystemNode
{
    public:
        virtual ~FileSystemNode();
        virtual long getSize() = 0;
        virtual std::string getTree(int level) = 0;
        void setName(const std::string name) { m_name = name; }
        std::string getName() { return m_name; }

    private:
        std::string m_name = "";
};

FileSystemNode::~FileSystemNode() {}

// Leaf
class File : public FileSystemNode
{
    public:
        virtual ~File() override;
        long getSize() override { return long(m_data.size()); }
        void setData(const std::string data) { m_data = data; }
        std::string getData() { return m_data; }

        std::string getTree(int level) override
        {
            std::string str = "";
            for (int i = 0; i < level; ++i) str += "    ";
            return str + getName() + " | data=\"" + getData() + "\" | " + std::to_string(getSize()) + " bytes\n";
        }

    private:
        std::string m_data = "";
};

File::~File() {}

// Composite
class Dir : public FileSystemNode
{
    public:
        virtual ~Dir() override;
        void addChild(FileSystemNode* child) { m_children.push_back(child); }
        long getSize() override
        {
            long total_size = 0;
            for (size_t i = 0; i < m_children.size(); ++i)
                total_size += m_children[i]->getSize();
            return total_size;
        }
        std::string getTree(int level) override
        {
            std::string str = "";
            for (int i = 0; i < level; ++i) str += "    ";
            str += getName() + "\n";
            for (size_t i = 0; i < m_children.size(); ++i)
                str += m_children[i]->getTree(level + 1);
            return str;
        }

    private:
        std::vector<FileSystemNode*> m_children;
};

Dir::~Dir()
{
    for (size_t i = 0; i < m_children.size(); ++i)
        delete m_children[i];
}

// Auxiliary function
Dir* createRoot()
{
    Dir* rootDir = new Dir;
    rootDir->setName("root");

    for (size_t i = 0; i < 4; ++i)
    {
        File* file = new File();
        file->setData(generateString(rand() % 20));
        file->setName("file" + std::to_string(i) + ".txt");
        rootDir->addChild(file);
    }

    for (size_t i = 0; i < 3; ++i)
    {
        Dir* subdir = new Dir();
        subdir->setName("subdir" + std::to_string(i));
        rootDir->addChild(subdir);

        for (size_t j = 0; j < 3; ++j)
        {
            File* file = new File();
            file->setData(generateString(rand() % 20));
            file->setName("file" + std::to_string(j) + ".txt");
            subdir->addChild(file);
        }

        for (size_t j = 0; j < 2; ++j)
        {
            Dir* subdir2 = new Dir();
            subdir2->setName("subdir" + std::to_string(j));
            subdir->addChild(subdir2);

            for (size_t k = 0; k < 2; ++k)
            {
                File* file = new File();
                file->setData(generateString(rand() % 20));
                file->setName("file" + std::to_string(k) + ".txt");
                subdir2->addChild(file);
            }
        }
    }

    return rootDir;
}

// Client
int main()
{
    Dir* root = createRoot();
    std::cout << "Total size: " << root->getSize() << std::endl;
    std::cout << "Tree: " << root->getTree(0) << std::endl;
    delete root;
}
