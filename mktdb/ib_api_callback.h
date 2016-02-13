#pragma once

#include "ibapi/EWrapper.h"

class IBApiCallback : public EWrapper
{
public:
   IBApiCallback();
   ~IBApiCallback();

   virtual void tickPrice(TickerId tickerId, TickType field, double price, int canAutoExecute) override;
   virtual void tickSize(TickerId tickerId, TickType field, int size) override;
   virtual void tickOptionComputation( TickerId tickerId, TickType tickType, double impliedVol, double delta,
       double optPrice, double pvDividend, double gamma, double vega, double theta, double undPrice) override;
   virtual void tickGeneric(TickerId tickerId, TickType tickType, double value) override;
   virtual void tickString(TickerId tickerId, TickType tickType, const IBString& value) override;
   virtual void tickEFP(TickerId tickerId, TickType tickType, double basisPoints, const IBString& formattedBasisPoints,
	   double totalDividends, int holdDays, const IBString& futureExpiry, double dividendImpact, double dividendsToExpiry) override;
   virtual void orderStatus( OrderId orderId, const IBString &status, int filled,
	   int remaining, double avgFillPrice, int permId, int parentId,
	   double lastFillPrice, int clientId, const IBString& whyHeld) override;
   virtual void openOrder( OrderId orderId, const Contract&, const Order&, const OrderState&) override;
   virtual void openOrderEnd() override;
   virtual void winError(const IBString &str, int lastError) override;
   virtual void connectionClosed() override;
   virtual void updateAccountValue(const IBString& key, const IBString& val,
       const IBString& currency, const IBString& accountName) override;
   virtual void updatePortfolio(const Contract& contract, int position,
       double marketPrice, double marketValue, double averageCost,
       double unrealizedPNL, double realizedPNL, const IBString& accountName) override;
   virtual void updateAccountTime(const IBString& timeStamp) override;
   virtual void accountDownloadEnd(const IBString& accountName) override;
   virtual void nextValidId(OrderId orderId) override;
   virtual void contractDetails(int reqId, const ContractDetails& contractDetails) override;
   virtual void bondContractDetails(int reqId, const ContractDetails& contractDetails) override;
   virtual void contractDetailsEnd(int reqId) override;
   virtual void execDetails(int reqId, const Contract& contract, const Execution& execution) override;
   virtual void execDetailsEnd(int reqId) override;
   virtual void error(const int id, const int errorCode, const IBString errorString) override;
   virtual void updateMktDepth(TickerId id, int position, int operation, int side,
       double price, int size) override;
   virtual void updateMktDepthL2(TickerId id, int position, IBString marketMaker, int operation,
       int side, double price, int size) override;
   virtual void updateNewsBulletin(int msgId, int msgType, const IBString& newsMessage, const IBString& originExch) override;
   virtual void managedAccounts(const IBString& accountsList) override;
   virtual void receiveFA(faDataType pFaDataType, const IBString& cxml) override;
   virtual void historicalData(TickerId reqId, const IBString& date, double open, double high, 
	   double low, double close, int volume, int barCount, double WAP, int hasGaps) override;
   virtual void scannerParameters(const IBString &xml) override;
   virtual void scannerData(int reqId, int rank, const ContractDetails &contractDetails,
	   const IBString &distance, const IBString &benchmark, const IBString &projection,
	   const IBString &legsStr) override;
   virtual void scannerDataEnd(int reqId) override;
   virtual void realtimeBar(TickerId reqId, long time, double open, double high, double low, double close,
	   long volume, double wap, int count) override;
   virtual void currentTime(long time) override;
   virtual void fundamentalData(TickerId reqId, const IBString& data) override;
   virtual void deltaNeutralValidation(int reqId, const UnderComp& underComp) override;
   virtual void tickSnapshotEnd(int reqId) override;
   virtual void marketDataType(TickerId reqId, int marketDataType) override;
   virtual void commissionReport(const CommissionReport &commissionReport) override;
   virtual void position(const IBString& account, const Contract& contract, int position, double avgCost) override;
   virtual void positionEnd() override;
   virtual void accountSummary(int reqId, const IBString& account, const IBString& tag, const IBString& value, const IBString& curency) override;
   virtual void accountSummaryEnd(int reqId) override;
   virtual void verifyMessageAPI(const IBString& apiData) override;
   virtual void verifyCompleted(bool isSuccessful, const IBString& errorText) override;
   virtual void displayGroupList(int reqId, const IBString& groups) override;
   virtual void displayGroupUpdated(int reqId, const IBString& contractInfo) override;
};