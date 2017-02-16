<?php
include "php/banco_conexao.php";
$cabecalho_title = "Editar páginas";
include "php/incusuarios.php";
?>
<section id="principal">
    <section id="crudpagina">
		<form action="crud-cadastra.php" method="post">
			<h3>Selecione uma das opções a baixo</h3>
			<input type="radio" name="crud" value="cadastrar"/>Inserir uma nova noticia<br/>
			<input type="radio" name="crud" value="atualizar"/>Editar uma noticia<br/>
			<input type="radio" name="crud" value="deletar"/>Excluir noticia<br/>
			<input type="submit" name="enviar" value="Enviar"/>
		</form>
        </section>
</section>
<?php
include "php/footer.php";
?>