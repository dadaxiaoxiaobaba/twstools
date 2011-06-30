#ifndef TWS_XML_H
#define TWS_XML_H


namespace IB {
	class ComboLeg;
	class UnderComp;
	class Contract;
	class ContractDetails;
}


typedef struct _xmlNode * xmlNodePtr;
typedef struct _xmlDoc * xmlDocPtr;


void conv_ib2xml( xmlNodePtr parent, const IB::ComboLeg& c,
	bool skip_defaults=false );
void conv_ib2xml( xmlNodePtr parent, const IB::UnderComp& c,
	bool skip_defaults=false );
void conv_ib2xml( xmlNodePtr parent, const IB::Contract& c,
	bool skip_defaults=false );
void conv_ib2xml( xmlNodePtr parent, const IB::ContractDetails& c,
	bool skip_defaults=false );

void conv_xml2ib( IB::ComboLeg* c, const xmlNodePtr node );
void conv_xml2ib( IB::UnderComp* c, const xmlNodePtr node );
void conv_xml2ib( IB::Contract* c, const xmlNodePtr node );
void conv_xml2ib( IB::ContractDetails* c, const xmlNodePtr node );




class IbXml
{
	public:
		IbXml();
		virtual ~IbXml();
		
		static void setSkipDefaults( bool );
		
		void dump() const;
		void add( const IB::Contract& cd );
		void add( const IB::ContractDetails& cd );
		
		xmlDocPtr getDoc() const;
		xmlNodePtr getRoot() const;
		
	private:
		static bool skip_defaults;
		
		xmlDocPtr doc;
		xmlNodePtr root;
};


#endif