/*Google Sheet -> Extensions -> Apps Script -> Code.gs*/
/*URL ->  Copy your Google sheet url*/

// Function to handle GET requests
function doGet(e) {
    // Open the specified Google Spreadsheet by its URL
    var ss = SpreadsheetApp.openByURL("https://docs.Google.com/spreadsheets/d/1se9WH29UU4-CmrPtGyQK1CAuT3wzpcceLQ9HtaVrK5U/edit#gid=0");
    
    // Get the sheet named "Sheet1"
    var sheet = ss.getSheetByName("Sheet1");
    
    // Call the addUser function to add a user with the provided parameters
    addUser(e, sheet);
}

// Function to handle POST requests
function doPost(e) {
    // Open the specified Google Spreadsheet by its URL
    var ss = SpreadsheetApp.openByURL("https://docs.Google.com/spreadsheets/d/1se9WH29UU4-CmrPtGyQK1CAuT3wzpcceLQ9HtaVrK5U/edit#gid=0");
    
    // Get the sheet named "Sheet1"
    var sheet = ss.getSheetByName("Sheet1");
    
    // Call the addUser function to add a user with the provided parameters
    addUser(e, sheet);
}

// Function to add a user to the spreadsheet
function addUser(e, sheet) {
    // Extract the name and contact from the event parameters
    var name = e.parameter.name;    // Get the 'name' parameter from the request
    var contact = e.parameter.contact; // Get the 'contact' parameter from the request
    
    // Append a new row to the sheet with the name and contact
    sheet.appendRow([name, contact]);
}

