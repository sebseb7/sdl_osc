#include <stdio.h>
#include <string.h>
#include <libxml2/libxml/parser.h>
#include <libxml2/libxml/tree.h>

#include "a.h"

#include "base64.h"


static char* decodeAttr(xmlNodePtr node,xmlChar *name)
{
	unsigned char *attr;
	size_t len  = xmlStrlen(xmlGetProp(node,name));
	size_t outlen;
	attr = base64_decode((char *)xmlGetProp(node,name),len,&outlen);
	char* retval = strndup((char *)attr,outlen+1);
	free(attr);
	retval[outlen]=0;

	return retval;
}


static void example1Func(const char *filename) {
	xmlDocPtr doc; /* the resulting document tree */

	doc = xmlReadFile(filename, NULL, 0);
	if (doc == NULL) {
		fprintf(stderr, "Failed to parse %s\n", filename);
		return;
	}

	xmlNodePtr cur = xmlFirstElementChild(xmlDocGetRootElement(doc));

	while (cur != NULL) 
	{
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"tabpage")))
		{
			printf("tab %s\n",decodeAttr(cur,(xmlChar*)"name"));
		}
		cur = cur->next;
	}


	fprintf(stdout, "ok\n");
	xmlFreeDoc(doc);
}

int main(int argc, char **argv) {
	LIBXML_TEST_VERSION

		example1Func("out.xml");

	xmlCleanupParser();
	xmlMemoryDump();
	return(0);
}
