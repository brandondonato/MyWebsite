//This function is implemented for smooth scrolling when clicking on the nav
$(document).ready(function(){
    // Add smooth scrolling to all links in navbar + footer link
    $(".navbar a, footer a[href='#myPage']").on('click', function(event) {
        // Make sure this.hash has a value before overriding default behavior
        if (this.hash !== "") {
            // Prevent default anchor click behavior and store the hash
            event.preventDefault()
            var hash = this.hash;
            
            // The number specifies the number of milliseconds it takes to scroll
            $('html, body').animate({
            scrollTop: $(hash).offset().top
            }, 1000, function(){
            // Add hash (#) to URL when done scrolling (default click behavior)
            window.location.hash = hash;
            });
        } 
    });
})
