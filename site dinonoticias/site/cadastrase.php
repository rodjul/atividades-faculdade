<?php
    $cabecalho_title = "Cadastro";
    include('php/cabecalho-e-menu.php');
?>
<section id="principal">
	<section id="noticias">
        <form action="cadastro.php" method="post" enctype="multipart/form-data">
            <label for="nome">Nome</label><input type="text" name="nome" value="" id="nome" /><br>
            <label for="login">Login:</label><input type="text" name="login" value="" id="login" /><br>
            <label for="senha">Senha:</label><input type="password" name="senha" value="" id="senha" /><br>
            <input type="hidden" name="MAX_SIZE_FILE" value="2000000" />
            Foto:<input type="file" name="arquivo" id="arquivo" /><br/>
            
            <input type="submit" value="Cadastrar" /><input type="reset" value="Cancelar" />
            
        </form>
	</section>
	<?php
    include('php/sites.php');
    ?>
</section>
<?php
    include('php/footer.php');
?>