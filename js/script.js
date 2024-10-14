document.querySelector("a[href='#equipe']").addEventListener("click", function(event) {
    event.preventDefault();

    const section = document.getElementById("equipe");
    
    section.scrollIntoView({ behavior: 'smooth' });
});
