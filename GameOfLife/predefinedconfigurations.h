#ifndef PREDEFINEDCONFIGURATIONS_H
#define PREDEFINEDCONFIGURATIONS_H
#include <vector>
#include <utility>

struct PredefinedConfiguration
{
    PredefinedConfiguration();
    std::vector<std::pair<int, int>> activeCells_;
};

struct GliderConfiguration: public PredefinedConfiguration
{
    GliderConfiguration();
};
/* This will be done later when needed
struct ExploderConfiguration: public PredefinedConfiguration
{
    ExploderConfiguration();
};

struct TumblerConfiguration: public PredefinedConfiguration
{
    TumblerConfiguration();
};
*/
#endif // PREDEFINEDCONFIGURATIONS_H
