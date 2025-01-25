(function() {
    'use strict';  
    

    // Set background to black
    document.body.style.backgroundColor = "#000000";  // Pure black background
    
    // Change form background to black for consistency
    let form = document.querySelectorAll('div.freebirdFormviewerViewFormContentWrapper');
    form.forEach((el) => {
        el.style.backgroundColor = "#000000";  // Black form background
        el.style.color = "#808080";  // Calm white (light grey) text
    });

    // Change text color to calm white and background of elements to transparent
    let texts = document.querySelectorAll('div, span, input, textarea, label');
    texts.forEach((el) => {
        el.style.color = "#e0e0e0";  // Calm white (light grey)
        el.style.backgroundColor = "transparent";  // Transparent background
    });

    // Change input fields to black background with calm white text and grey borders
    let inputs = document.querySelectorAll('input[type="text"], textarea');
    inputs.forEach((el) => {
        el.style.backgroundColor = "#000000";  // Black background for inputs
        el.style.borderColor = "#555555";  // Muted grey border
        el.style.color = "#808080";  // Calm white (light grey) text
    });

    // Change header background to black and text to calm white
    let headers = document.querySelectorAll('header, .freebirdFormviewerViewHeader');
    headers.forEach((el) => {
        el.style.backgroundColor = "#000000";  // Black background for header
        el.style.color = "#808080";  // Calm white (light grey) text
    });

    // Adjust button colors to have black background and calm white text
    let buttons = document.querySelectorAll('div[role="button"]');
    buttons.forEach((el) => {
        el.style.backgroundColor = "#222222";  // Dark grey button background
        el.style.color = "#808080";  // Calm white (light grey) button text
        el.style.border = "1px solid #555555";  // Muted grey border
    });

})();
