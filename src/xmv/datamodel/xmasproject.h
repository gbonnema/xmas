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

    void saveNetwork(const std::string& filename, XMASNetwork* network = nullptr);

private:
    bitpowder::lib::MemoryPool m_mp;
    std::map<std::string, std::unique_ptr<XMASNetwork>>  networks;
    XMASNetwork* root;

    XMASNetwork* loadNetwork(const std::string& filename);
};

#endif // XMASPROJECT_H
