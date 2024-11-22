document.addEventListener("DOMContentLoaded", function () {
  const menuToggle = document.getElementById("menuToggle");
  const menuItens = document.getElementById("menuItens");
  const nav = document.querySelector(".menu-nav");
  let lastScrollTop = 0;
  let scrollTimeout;

  menuToggle.addEventListener("click", function () {
    menuItens.classList.toggle("active");
  });

  window.addEventListener("scroll", function () {
    const scrollTop = window.pageYOffset || document.documentElement.scrollTop;

    if (scrollTop > lastScrollTop) {
      // Scrolling down
      nav.classList.remove("visible");
      nav.classList.add("hidden");
      clearTimeout(scrollTimeout);
    } else {
      // Scrolling up
      clearTimeout(scrollTimeout);
      scrollTimeout = setTimeout(() => {
        nav.classList.remove("hidden");
        nav.classList.add("visible");
      }, 300); // Atraso de 300ms antes de mostrar a navegação novamente
    }

    lastScrollTop = scrollTop <= 0 ? 0 : scrollTop; // For Mobile or negative scrolling
  });
});

document.addEventListener("DOMContentLoaded", () => {
  const prevBtn = document.getElementById("prevBtn");
  const nextBtn = document.getElementById("nextBtn");
  const imageBackgrounds = document.querySelectorAll(".image-background");
  let currentIndex = 0;

  function updateImageVisibility() {
    imageBackgrounds.forEach((background, index) => {
      background.style.display = index === currentIndex ? "flex" : "none";
    });
  }

  prevBtn.addEventListener("click", () => {
    if (currentIndex > 0) {
      currentIndex--;
    } else {
      currentIndex = imageBackgrounds.length - 1; // Loop para o final
    }
    updateImageVisibility();
  });

  nextBtn.addEventListener("click", () => {
    if (currentIndex < imageBackgrounds.length - 1) {
      currentIndex++;
    } else {
      currentIndex = 0; // Loop para o início
    }
    updateImageVisibility();
  });

  updateImageVisibility();
});

document.addEventListener("DOMContentLoaded", () => {
  const cards = document.querySelectorAll(".card");
  const modal = document.getElementById("modal");
  const modalText = document.getElementById("modal-text");
  const closeBtn = document.querySelector(".close-btn");
  const prevCardBtn = document.getElementById("prevCardBtn");
  const nextCardBtn = document.getElementById("nextCardBtn");
  let currentIndex = 0;

  function updateCardVisibility() {
    const cardsPerPage = window.innerWidth <= 768 ? 1 : 4; // Ajuste o número de cards por página conforme necessário
    cards.forEach((card, index) => {
      card.style.display =
        index >= currentIndex && index < currentIndex + cardsPerPage
          ? "block"
          : "none";
    });
  }

  prevCardBtn.addEventListener("click", () => {
    if (currentIndex > 0) {
      currentIndex--;
    } else {
      currentIndex = cards.length - (window.innerWidth <= 768 ? 1 : 4); // Ajuste o número de cards por página conforme necessário
    }
    updateCardVisibility();
  });

  nextCardBtn.addEventListener("click", () => {
    if (currentIndex < cards.length - (window.innerWidth <= 768 ? 1 : 4)) {
      currentIndex++;
    } else {
      currentIndex = 0; // Loop para o início
    }
    updateCardVisibility();
  });

  document.querySelectorAll(".saiba-mais-btn").forEach((btn) => {
    btn.addEventListener("click", (e) => {
      const modalId = e.target.getAttribute("data-modal");
      modalText.innerHTML = document.getElementById(modalId).innerHTML;
      modal.style.display = "block";
    });
  });

  closeBtn.addEventListener("click", () => {
    modal.style.display = "none";
  });

  window.addEventListener("click", (e) => {
    if (e.target == modal) {
      modal.style.display = "none";
    }
  });

  // Inicializa a visibilidade dos cards
  updateCardVisibility();
  window.addEventListener("resize", updateCardVisibility); // Atualiza a visibilidade dos cards ao redimensionar a janela
});
