#include "predefinedconfigurations.h"
#include <QDebug>

Configuration::Configuration()
{

}

GliderConfiguration::GliderConfiguration()
{
    activeCells_.push_back({3, 4});
    activeCells_.push_back({4, 4});
    activeCells_.push_back({5, 4});
    activeCells_.push_back({3, 5});
    activeCells_.push_back({4, 6});
    qDebug() << "Glider was created!";
}
