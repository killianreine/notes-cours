document.addEventListener("DOMContentLoaded", () => {
  ["q1","q2"].forEach(id => {
    let el = document.getElementById(id);
    if (localStorage.getItem(id)) {
      el.value = localStorage.getItem(id);
    }
    el.addEventListener("input", () => {
      localStorage.setItem(id, el.value);
    });
  });

  document.getElementById("sendBtn").addEventListener("click", () => {
    let answers = `Q1: ${document.getElementById("q1").value}\nQ2: ${document.getElementById("q2").value}`;
    let mailto = `mailto:killian.reine@etu.univ-lehavre.fr?subject=Cours%20a%20trous&body=${encodeURIComponent(answers)}`;
    window.location.href = mailto;
  });
});

