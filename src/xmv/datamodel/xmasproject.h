#ifndef XMASPROJECT_H
#define XMASPROJECT_H

#include "string.h"
#include "xmas.h"

class XMASProject
{
public:
    XMASProject();
    XMASProject(const std::string& filename);
    ~XMASProject();

    bitpowder::lib::MemoryPool& mp() { return m_mp; }

    XMASNetwork* getRootNetwork() const { return root; }
    const XMASNetwork* getNetwork(const std::string name) const { return networks.find(name)->second.get(); }

    XMASNetwork* loadNetwork(const std::string& filename);
    void saveNetwork(const std::string& filename, XMASNetwork* network = nullptr);

    template <class T, typename... Args>
    T *insert(const bitpowder::lib::String& name, Args... args) {
        return root->insert<T>(m_mp, name, args...);
    }

    XMASComponent *insertSource(const bitpowder::lib::String& name, bool external = false);
    XMASComponent *insertSink(const bitpowder::lib::String& name, bool external = false);
    XMASComponent *insertFunction(const bitpowder::lib::String& name);
    XMASComponent *insertQueue(const bitpowder::lib::String& name, size_t capacity = 1);
    XMASComponent *insertJoin(const bitpowder::lib::String& name);
    XMASComponent *insertMerge(const bitpowder::lib::String& name);
    XMASComponent *insertSwitch(const bitpowder::lib::String& name);
    XMASComponent *insertFork(const bitpowder::lib::String& name);
    XMASComponent *insertComposite(const bitpowder::lib::String& name, XMASNetwork& network);

    bool changeComponentName(std::string oldName, std::string newName);

private:
    bitpowder::lib::MemoryPool m_mp;
    std::map<std::string, std::unique_ptr<XMASNetwork>>  networks;
    XMASNetwork* root;

};

#endif // XMASPROJECT_H
