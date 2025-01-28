#ifndef XML_VALIDATOR_H
#define XML_VALIDATOR_H

#include <string>

// Function to validate an XML file against an XSD schema
void validateXML(const std::string& xmlPath, const std::string& schemaPath);

#endif // XML_VALIDATOR_H
