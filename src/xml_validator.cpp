// #include "../include/xml_validator.h"
// #include <iostream>
// #include <libxml/parser.h>
// #include <libxml/xmlschemas.h>

// void validateXML(const std::string& xmlPath, const std::string& schemaPath) {
//     xmlDocPtr schemaDoc = nullptr;
//     xmlSchemaParserCtxtPtr parserCtxt = nullptr;
//     xmlSchemaPtr schema = nullptr;
//     xmlSchemaValidCtxtPtr validCtxt = nullptr;
//     xmlDocPtr doc = nullptr;

//     try {
//         // Load the schema
//         parserCtxt = xmlSchemaNewParserCtxt(schemaPath.c_str());
//         if (!parserCtxt) {
//             throw std::runtime_error("Failed to create schema parsing context.");
//         }

//         schema = xmlSchemaParse(parserCtxt);
//         if (!schema) {
//             throw std::runtime_error("Failed to parse schema.");
//         }

//         validCtxt = xmlSchemaNewValidCtxt(schema);
//         if (!validCtxt) {
//             throw std::runtime_error("Failed to create schema validation context.");
//         }

//         // Load the XML file
//         doc = xmlReadFile(xmlPath.c_str(), nullptr, 0);
//         if (!doc) {
//             throw std::runtime_error("Failed to parse XML file.");
//         }

//         // Validate the XML against the schema
//         if (xmlSchemaValidateDoc(validCtxt, doc) == 0) {
//             std::cout << "The XML file is valid against the provided schema." << std::endl;
//         } else {
//             std::cout << "The XML file is NOT valid." << std::endl;
//         }
//     } catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//     }

//     // Cleanup
//     if (doc) xmlFreeDoc(doc);
//     if (validCtxt) xmlSchemaFreeValidCtxt(validCtxt);
//     if (schema) xmlSchemaFree(schema);
//     if (parserCtxt) xmlSchemaFreeParserCtxt(parserCtxt);
//     xmlCleanupParser();
// }
