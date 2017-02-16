<?php
include "php/banco_conexao.php";
$cabecalho_title = "Editar página";
?>

<?php
$opcao = $_POST["crud"];
	switch($opcao)
	{			
		case "cadastrar":
			$formulario='<h3>Editando Notícias</h3>
			<form action="php/create.php" method="post">
				<label for="titulo"/>Titulo:</br><input type="text" name="titulo"/><br/>
				<label for="autor"/>Autor:</br><input type="text" name="autor"/><br/>
				<p>Escolha o tipo de noticia que irá inserir:</p>
				<input type="radio" name="noticias" value="atualidades"/>Atualidades<br/>
				<input type="radio" name="noticias" value="economia"/>Economia<br/>
				<input type="radio" name="noticias" value="esportes"/>Esportes<br/>
				<input type="radio" name="noticias" value="celebridades"/>Celebridades<br/>
				<input type="radio" name="noticias" value="mundo"/>Mundo<br/><br/>
				<input type="file" name="arquivo"/><br/>
                <p>Insira o texto da notícia:</p>
				<textarea name="texto" rows="20" cols="70"> </textarea>
				<input type="submit" name="enviar" value="Enviar"/>
			</form>';
		break;
		
		case "atualizar":
			$formulario="<h3>Atualizar</h3>
					     <form action='php/update.php' method='post'>
								idAluno:<input type='text' name='id'/><br/>
								nome:<input type='text' name='nome'/><br/>
								nota:<input type='text' name='nota'/><br/>
								<input type='submit' value='ATUALIZAR'>
						</form>";
		break;
		
		case "deletar":
			$formulario="<form action='php/delete.php' method='post'>
							idAluno:ss<input type='text' name='id'><br/>
							<input type='submit' value='APAGAR'>
						  </form>";
		break;					
	}
	include "php/incusuarios.php";
    echo "<section id='editarpag'>";
	echo $formulario;
    echo "</section>";
    include "php/footer.php";
	
?>
