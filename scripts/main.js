document.addEventListener("DOMContentLoaded", () => {
  const body = document.body;
  const themeToggle = document.querySelector(".theme-toggle");
  const prefersDark = window.matchMedia("(prefers-color-scheme: dark)");
  const storedTheme = localStorage.getItem("mutatum-theme");
  const menuButton = document.querySelector(".nav-toggle");
  const menu = document.querySelector(".main-nav ul");
  const backToTop = document.querySelector(".back-to-top");
  const yearEl = document.getElementById("year");

  const applyTheme = (theme) => {
    if (theme === "light") {
      body.classList.add("light-theme");
    } else {
      body.classList.remove("light-theme");
    }
    localStorage.setItem("mutatum-theme", theme);
  };

  const initTheme = () => {
    if (storedTheme) {
      applyTheme(storedTheme);
    } else if (!prefersDark.matches) {
      applyTheme("light");
    }
  };

  initTheme();

  themeToggle?.addEventListener("click", () => {
    const nextTheme = body.classList.contains("light-theme") ? "dark" : "light";
    applyTheme(nextTheme);
  });

  menuButton?.addEventListener("click", () => {
    const expanded = menuButton.getAttribute("aria-expanded") === "true";
    menuButton.setAttribute("aria-expanded", String(!expanded));
    if (menu) {
      menu.setAttribute("aria-expanded", String(!expanded));
      menu.classList.toggle("nav-open", !expanded);
    }
  });

  menu?.querySelectorAll("a").forEach((link) => {
    link.addEventListener("click", () => {
      if (window.innerWidth <= 880 && menuButton) {
        menuButton.setAttribute("aria-expanded", "false");
        menu?.classList.remove("nav-open");
      }
    });
  });

  if (yearEl) {
    yearEl.textContent = new Date().getFullYear();
  }

  const observer = new IntersectionObserver(
    (entries) => {
      entries.forEach((entry) => {
        entry.target.classList.toggle("is-visible", entry.isIntersecting);
      });
    },
    { threshold: 0.2 }
  );

  document.querySelectorAll(".section, .hero-card, .experience-card, .project-card, .skill-block, .interest-card").forEach((el) => {
    observer.observe(el);
  });

  backToTop?.addEventListener("click", (event) => {
    event.preventDefault();
    window.scrollTo({ top: 0, behavior: "smooth" });
  });
});
