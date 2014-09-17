$(function(){

var count;
$("#generate").click( function() {
    $("#rand_num").val(Math.ceil(Math.random() * 100));
    $("#guess_text").html("Guess the number!It is between 1 and 100");
    $("#guess_section").show();
    $("#game_over").hide();
    count = 0;
});

$("#compare").click( function() {
    count += 1;
    if (isNaN($("#input").val())) {
        $("#guess_text").html("This is not a number. Please, write a number! You have made "+count+" guesses.");
    } else if (parseInt($("#input").val()) < 1 || parseInt($("#input").val()) > 100) {
        $("#guess_text").html("Remember, your number must be between 1 and 100! You have made "+count+" guesses.");
    } else {
        if (parseInt($("#input").val()) == $("#rand_num").val()) {
           /*$("#guess_text").html("Correct! It took you " + count + " guesses."); */
            $("#guess_section").hide();
            $("#game_over_text").html("Correct! It took you " + count + " guesses.");
            $("#game_over").show();
        }
        else if(parseInt($("#input").val()) < $("#rand_num").val()){
             $("#guess_text").html("Your guess was too low! You have made "+count+" guesses.");   
        }
        else if(parseInt($("#input").val()) > $("#rand_num").val()){
             $("#guess_text").html("Your guess was too high! You have made "+count+" guesses.");   
        }
        else {
            $("#guess_text").html("Incorrect! Please try again! You have made "+count+" guesses.");
        }
    }
});
});