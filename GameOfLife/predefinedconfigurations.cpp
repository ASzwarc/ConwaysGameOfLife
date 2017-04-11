#include "predefinedconfigurations.h"
#include <QDebug>

Configuration::Configuration()
{

}

GliderConfiguration::GliderConfiguration()
{
    activeCells_.push_back({3, 3});
    activeCells_.push_back({3, 4});
    activeCells_.push_back({3, 5});
    activeCells_.push_back({4, 3});
    activeCells_.push_back({5, 4});
    qDebug() << "Glider was created!";
}
