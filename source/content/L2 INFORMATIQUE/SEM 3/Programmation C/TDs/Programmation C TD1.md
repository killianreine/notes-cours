<div>
<p>En C, la fonction principale s’écrit 
  <input type="text" id="q1" placeholder="réponse attendue">
</p>
<p>Pour afficher du texte, on utilise 
  <input type="text" id="q2" placeholder="réponse attendue">
</p>
<button onclick="saveAnswers()">💾 Sauvegarder</button>
<button onclick="sendAnswers()">📧 Envoyer mes réponses</button>
<script>
// Charger les réponses depuis localStorage
document.addEventListener("DOMContentLoaded", () => {
  ["q1","q2"].forEach(id => {
    if(localStorage.getItem(id)){
      document.getElementById(id).value = localStorage.getItem(id);
    }
  });
});
// Sauvegarde locale
function saveAnswers() {
  ["q1","q2"].forEach(id => {
    localStorage.setItem(id, document.getElementById(id).value);
  });
  alert("Réponses sauvegardées !");
}
// Envoi par email (ouvre le client mail avec les réponses)
function sendAnswers() {
  let answers = `Q1: ${document.getElementById("q1").value}\nQ2: ${document.getElementById("q2").value}`;
  let mailto = `mailto:killian.reine@etu.univ-lehavre.fr?subject=Cours%20a%20trous&body=${encodeURIComponent(answers)}`;
  window.location.href = mailto;
}
</script>
</div>
