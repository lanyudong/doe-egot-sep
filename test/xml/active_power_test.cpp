#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <gtest/gtest.h>
#include <sep/active_power.hpp>
#include <xml/active_power_adapter.hpp>
#include "xml_validator.hpp"

class TestActivePowerXML : public ::testing::Test 
{
protected:
    void SetUp() override 
    {        
        active_power = std::make_shared<sep::ActivePower>();
        active_power_xml = std::make_shared<xml::ActivePowerAdapter>(active_power);
        XMLPlatformUtils::Initialize();

        // read in the sample file
        std::ifstream ifs("./sep_examples/ActivePower.xml");
        if (ifs)
        {
            std::ostringstream oss;
            oss << ifs.rdbuf();
            xml_str = oss.str();        
        }
        else
        {
            std::cout << "couldn't open xml file" << std::endl;
        };
    }

    void TearDown() override
    {
        XMLPlatformUtils::Terminate(); 
    }

protected:
    const char *xsd_path = "./sep.xsd";
    std::string xml_str;
    std::shared_ptr<sep::ActivePower> active_power;
    xml::ActivePowerAdapter active_power_xml;
};

TEST_F(TestActivePowerXML, IsSampleValid) 
{    
    bool valid = ValidateSchema(xsd_path, xml_str);
    EXPECT_EQ(valid, true);       
}

TEST_F(TestActivePowerXML, IsAdapterParseValid) 
{    
    active_power_xml->parse(xml_str);
    std::cout << "HERE" << std::endl;
    EXPECT_EQ(active_power_xml->active_power->multiplier, 1);
    EXPECT_EQ(active_power_xml->active_power->value, -32000);  
}

TEST_F(TestActivePowerXML, IsAdapterSerializeValid)
{    
    boost::property_tree::ptree pt = active_power_xml->treeify(xml_str);
    std::string adapter_xml = active_power_xml->serialize(pt);
    bool valid = ValidateSchema(xsd_path, adapter_xml);
    EXPECT_EQ(valid, true);    
}