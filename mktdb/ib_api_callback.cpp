#include "pch.h"
#pragma hdrstop

#include "ib_api_callback.h"

IBApiCallback::IBApiCallback()
{
}

IBApiCallback::~IBApiCallback()
{
}

void IBApiCallback::tickPrice(TickerId tickerId, TickType field, double price, int canAutoExecute) 
{
    echo("tickPrice\n");
}

void IBApiCallback::tickSize(TickerId tickerId, TickType field, int size) 
{
    echo("tickSize\n");
}

void IBApiCallback::tickOptionComputation(TickerId tickerId, TickType tickType, double impliedVol, double delta,
                                          double optPrice, double pvDividend, double gamma, double vega, double theta, double undPrice) 
{
    echo("tickOptionComputation\n");
}

void IBApiCallback::tickGeneric(TickerId tickerId, TickType tickType, double value) 
{
    echo("tickGeneric\n");
}

void IBApiCallback::tickString(TickerId tickerId, TickType tickType, const IBString& value) 
{
    echo("tickString\n");
}

void IBApiCallback::tickEFP(TickerId tickerId, TickType tickType, double basisPoints, const IBString& formattedBasisPoints,
                            double totalDividends, int holdDays, const IBString& futureExpiry, double dividendImpact, double dividendsToExpiry) 
{
    echo("tickEFP\n");
}

void IBApiCallback::orderStatus(OrderId orderId, const IBString& status, int filled,
                                int remaining, double avgFillPrice, int permId, int parentId,
                                double lastFillPrice, int clientId, const IBString& whyHeld) 
{
    echo("orderStatus\n");
}

void IBApiCallback::openOrder(OrderId orderId, const Contract&, const Order&, const OrderState&) 
{
    echo("openOrder\n");
}

void IBApiCallback::openOrderEnd() 
{
    echo("openOrderEnd\n");
}

void IBApiCallback::winError(const IBString& str, int lastError)
{
    echo("winError: %s, last error code: %d\n", str.c_str(), lastError);
}

void IBApiCallback::connectionClosed() 
{
    echo("connectionClosed\n");
}

void IBApiCallback::updateAccountValue(const IBString& key, const IBString& val, const IBString& currency, const IBString& accountName) 
{
    echo("updateAccountValue\n");
}
    
void IBApiCallback::updatePortfolio(const Contract& contract, int position,
                            double marketPrice, double marketValue, double averageCost,
                            double unrealizedPNL, double realizedPNL, const IBString& accountName)
{
    echo("updatePortfolio\n");
}
    
void IBApiCallback::updateAccountTime(const IBString& timeStamp) 
{
    echo("updateAccountTime\n");
}
   
void IBApiCallback::accountDownloadEnd(const IBString& accountName) 
{
    echo("accountDownloadEnd\n");
}
    
void IBApiCallback::nextValidId(OrderId orderId)
{
    echo("nextValidId: %d\n", orderId);
}
    
void IBApiCallback::contractDetails(int reqId, const ContractDetails& contractDetails) 
{
    echo("contractDetails\n");
}
    
void IBApiCallback::bondContractDetails(int reqId, const ContractDetails& contractDetails) 
{
    echo("bondContractDetails\n");
}
    
void IBApiCallback::contractDetailsEnd(int reqId) 
{
    echo("contractDetailsEnd\n");
}
    
void IBApiCallback::execDetails(int reqId, const Contract& contract, const Execution& execution) 
{
    echo("execDetails\n");
}
    
void IBApiCallback::execDetailsEnd(int reqId) 
{
    echo("execDetailsEnd\n");
}
   
void IBApiCallback::error(const int id, const int errorCode, const IBString errorString) 
{
    echo("error: %d - %s\n", 
           errorCode,
           errorString.c_str());
    //OutputDebugStringA(errorString.c_str());
}
    
void IBApiCallback::updateMktDepth(TickerId id, int position, int operation, int side, double price, int size) 
{
    echo("updateMktDepth\n");
}
    
void IBApiCallback::updateMktDepthL2(TickerId id, int position, IBString marketMaker, int operation,
                             int side, double price, int size) 
{
    echo("updateMktDepthL2\n");
}
    
void IBApiCallback::updateNewsBulletin(int msgId, int msgType, const IBString& newsMessage, const IBString& originExch) 
{
    echo("updateNewsBulletin\n");
}
    
void IBApiCallback::managedAccounts( const IBString& accountsList) 
{
    echo("managedAccounts\n");
}
    
void IBApiCallback::receiveFA(faDataType pFaDataType, const IBString& cxml) 
{
    echo("receiveFA\n");
}

void IBApiCallback::historicalData(TickerId reqId, const IBString& date, double open, double high, 
                                   double low, double close, int volume, int barCount, double WAP, int hasGaps)
{
    if (open >= 0)
    {
        echo("historicalData\n");
    }
    else
    {
        echo("end of historicalData\n");
    }
}

void IBApiCallback::scannerParameters(const IBString &xml)
{
    echo("scannerParameters\n");
}

void IBApiCallback::scannerData(int reqId, int rank, const ContractDetails& contractDetails,
                        const IBString& distance, const IBString& benchmark, const IBString& projection,
                        const IBString& legsStr) 
{
    echo("scannerData\n");
}
    
void IBApiCallback::scannerDataEnd(int reqId) 
{
    echo("scannerDataEnd\n");
}
    
void IBApiCallback::realtimeBar(TickerId reqId, long time, double open, double high, double low, double close, long volume, double wap, int count) 
{
    echo("realtimeBar\n");
}
    
void IBApiCallback::currentTime(long time)
{
    time_t t = (time_t)time;
	struct tm *timeinfo = localtime(&t);
	//echo("%s", asctime(timeinfo));
}
    
void IBApiCallback::fundamentalData(TickerId reqId, const IBString& data) 
{
    echo("fundamentalData\n");
}
    
void IBApiCallback::deltaNeutralValidation(int reqId, const UnderComp& underComp) 
{
    echo("deltaNeutralValidation\n");
}

void IBApiCallback::tickSnapshotEnd(int reqId) 
{
    echo("tickSnapshotEnd\n");
}
    
void IBApiCallback::marketDataType(TickerId reqId, int marketDataType) 
{
    echo("marketDataType\n");
}
    
void IBApiCallback::commissionReport(const CommissionReport& commissionReport) 
{
    echo("commissionReport\n");
}
    
void IBApiCallback::position(const IBString& account, const Contract& contract, int position, double avgCost) 
{
    echo("position\n");
}
    
void IBApiCallback::positionEnd() 
{
    echo("positionEnd\n");
}
    
void IBApiCallback::accountSummary(int reqId, const IBString& account, const IBString& tag, const IBString& value, const IBString& currency) 
{
    echo("accountSummary\n");
}
    
void IBApiCallback::accountSummaryEnd(int reqId) 
{
    echo("accountSummaryEnd\n");
}
    
void IBApiCallback::verifyMessageAPI(const IBString& apiData) 
{
    echo("verifyMessageAPI\n");
}
    
void IBApiCallback::verifyCompleted(bool isSuccessful, const IBString& errorText) 
{
    echo("verifyCompleted\n");
}
    
void IBApiCallback::displayGroupList(int reqId, const IBString& groups) 
{
    echo("displayGroupList\n");
}
    
void IBApiCallback::displayGroupUpdated(int reqId, const IBString& contractInfo) 
{
    echo("displayGroupUpdated\n");
}